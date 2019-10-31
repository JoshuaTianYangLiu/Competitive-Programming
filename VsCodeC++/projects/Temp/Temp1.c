/*The code to turn off all bulbs in a matrix of bulbs
*/

#include <stdio.h>
#include <smmintrin.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
typedef char ** MATRIX;
typedef char * VECTOR;
typedef char *const* CONST_MATRIX;
typedef const char * CONST_VECTOR;

MATRIX matrix_alloc2(int n, int m){
	MATRIX x= (MATRIX)malloc(sizeof(char *)*n+sizeof(char)*n*m);
	int i;
	x[0]=(char *)(x+n);
	for(i=1;i<n;i++)x[i]=x[i-1]+m;
	return x;
}

int maxtrix_count_one(MATRIX x,int n, int m){
	int r=0;
	int i,j;
	for(i=0;i<n;i++)for(j=0;j<n;j++)if(x[i][j]!=0)r++;
	return r;
}

MATRIX matrix_alloc(int n){
    MATRIX x = (MATRIX)malloc(sizeof(char *)*n+sizeof(char)*n*n);
    int i;
    x[0]=(char *)(x+n);
    for(i=1;i<n;i++)x[i]=x[i-1]+n;
    return x;
}

void matrix_free(MATRIX x){
    free(x);
}

VECTOR vector_alloc(int n){
    VECTOR x = (VECTOR)malloc(sizeof(char)*n);
    return x;
}

void vector_free(VECTOR x){
    free(x);
}

void matrix_sum(MATRIX A, CONST_MATRIX B, int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A[i][j] ^= B[i][j];
        }
    }
}

void vector_sum(VECTOR a, CONST_VECTOR b, int n){
    int i;
    for(i=0;i<n;i++)a[i]^=b[i];
}

void matrix_mul(MATRIX out, CONST_MATRIX in1, CONST_MATRIX in2, int n){
    int i,j,k;
    for(i=0;i<n;i++)for(j=0;j<n;j++){
        int sum=0;
        for(k=0;k<n;k++){
            if(in1[i][k])
                sum^=in2[k][j];
        }
        out[i][j]=sum;
    }
}

void matrix_mul_H(MATRIX out, CONST_MATRIX in, int n){
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++){
        int sum=in[i][j];
        if(i>0)sum^=in[i-1][j];
        if(i<n-1)sum^=in[i+1][j];
        out[i][j]=sum;
    }
}

void matrix_mul_vector(VECTOR out, CONST_MATRIX m, CONST_VECTOR in, int n){
    int i,j;
    for(i=0;i<n;i++){
        int sum=0;
        for(j=0;j<n;j++){
            sum^=m[i][j]&in[j];
        }
        out[i]=sum;
    }
}

void H_mul_vector(VECTOR out, CONST_VECTOR in, int n){
    int i;
    for(i=0;i<n;i++){
        int sum=in[i];
        if(i>0)sum^=in[i-1];
        if(i<n-1)sum^=in[i+1];
        out[i]=sum;
    }
}

void vector_init_const(VECTOR v, char c, int n){
    int i;
    for(i=0;i<n;i++)v[i]=c;
}

void matrix_init_O(MATRIX o, int n){
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++)o[i][j]=0;
}

void matrix_init_const(MATRIX m, char c, int n1, int n2){
    int i,j;
    for(i=0;i<n1;i++)for(j=0;j<n2;j++)m[i][j]=c;
}

void matrix_init_E(MATRIX e, int n){
    int j;
    matrix_init_O(e,n);
    for(j=0;j<n;j++)e[j][j]=1;
}

void matrix_init_H(MATRIX h, int n){
    int i;
    matrix_init_O(h,n);
    for(i=0;i<n;i++){
        if(i>=1)h[i][i-1]=1;
        h[i][i]=1;
        if(i<n-1)h[i][i+1]=1;
    }
}

void matrix_copy(MATRIX m, CONST_MATRIX k, int n){
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++)m[i][j]=k[i][j];
}

void matrix_copy2(MATRIX m, CONST_MATRIX k, int n1, int n2){
    int i,j;
    for(i=0;i<n1;i++)for(j=0;j<n2;j++)m[i][j]=k[i][j];
}

void vector_copy(VECTOR v, CONST_VECTOR w, int n){
    int i;
    for(i=0;i<n;i++)v[i]=w[i];
}

void matrix_output2(CONST_MATRIX m, int n1, int n2){
    int i,j;
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            printf("%d",m[i][j]);
        }
        printf("\n");
    }
}

void matrix_output(CONST_MATRIX m, int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",m[i][j]);
        }
        printf("\n");
    }
}
void vector_output(VECTOR v, int n){
    int i;
    for(i=0;i<n;i++)printf("%d",v[i]);
    printf("\n");
}

void Usage(const char *program_name){
    printf("Usage:\n");
    printf("\t$%s n\n",program_name);
    printf("\t\twhere n is a positive integer no more than %d\n", N);
    printf("The program assumes there're an n*n array. Each cell in the array has a switch "
        "and a light. On touches of the switch in a cell will changes the state of the "
        "light in the cell as well as the lights in the neighbors of the cell, so that "
        "one switch could change states of 5 lights at most\n");
    printf("The program will try to find minimal touches of switches to turn all lights off while originally all lights are on\n");
    exit(-1);
}

MATRIX P0,P1,H;
VECTOR ME;
MATRIX init;

static void copy_matrix_to_bit_string(MATRIX x, int m, int n, unsigned long long *bitstrings, int ll_len)
{
    int i,j;
    memset(bitstrings, 0, ll_len*sizeof(unsigned long long));
    for(i=0;i<n;i++){
         for(j=0;j<m;j++){
            if(x[i][j]!=0){
               int index=i*m+j;
               int word = index/64;
               int off = index%64;
               bitstrings[word]|=1ll<<off;
            } 
         }
    }
}

int count_one(const unsigned long long *x, int ll_len)
{
   int r=0;
   int i;
   const unsigned int *p=(const unsigned int*)x;
   for(i=0;i<2*ll_len;i++)r+=__builtin_popcount(p[i]);
   return r;
}

static void llxor(unsigned long long *r,  const unsigned long long *x, int ll_len)
{
    int i;
    for(i=0;i<ll_len;i++)r[i]^=x[i];
}


 void search_base_result(const unsigned long long *any_root, const unsigned long long *base, int base_count, int ll_len)
{
    long long x;
    int j;
    unsigned long long *best_r = (unsigned long long *)malloc(ll_len*sizeof(unsigned long long));
    unsigned long long *cur_r = (unsigned long long *)malloc(ll_len*sizeof(unsigned long long));
    int best_count = count_one(any_root, ll_len);
    memcpy(best_r, any_root, ll_len*sizeof(unsigned long long));
    memcpy(cur_r, any_root, ll_len*sizeof(unsigned long long));
    for(x=1LL;x<=(1LL<<base_count)-1;x++){
       for(j=0;j<base_count&&(x&(1LL<<j))==0;j++){
          llxor(cur_r, base+j*ll_len, ll_len);
       }
       llxor(cur_r, base+j*ll_len, ll_len);
       int cur_count = count_one(cur_r, ll_len);
       if(cur_count<best_count){
           best_count = cur_count;
           memcpy(best_r, cur_r, ll_len*sizeof(unsigned long long));
       }
    }
    free(best_r);
    free(cur_r);
    printf("best count:%d\n",best_count);
}

//First we need to solve equation P*X(n) = ME;
//There could be multiple solutions
//For each solution X(n), try
//X(n-1) = INIT+ H*X(n);
//X(K)   = INIT + H*X(k+1)+X(k+2);//for k<n-1
void Solve(MATRIX P, VECTOR ME, int n, int m)
{
    int *freedom_index;
    int freedom_count=0;
    int i,j,k,t;
    int failed=0;
    int longlong_len = (n*m+63)/64;
    freedom_index = (int *)malloc(sizeof(int)*m);
    //First solve equition P*X(n) = ME
    for(i=0,t=0;i<m;i++){
        for(j=t;j<m;j++)if(P[j][i]==1)break;
        if(j==m){
            //find a freedom factor
            freedom_index[freedom_count++]=i;
        }else{
            if(j!=t){
                //Swap line j and t
                int temp;
                for(k=i;k<m;k++){
                    temp=P[t][k];
                    P[t][k]=P[j][k];
                    P[j][k]=temp;
                }
                temp = ME[t];
                ME[t] = ME[j];
                ME[j] = temp;
            }
            for(j=0;j<m;j++){
                if(j!=t&&P[j][i]){
                    //If P[j][i] is 1, add Line i into Line j
                    for(k=i;k<m;k++){
                        P[j][k]^=P[t][k];
                    }
                    ME[j]^=ME[t];
                }
            }
			t++;
        }
    }
	for(;t<m;t++){
		if(ME[t]!=0){
			failed=1;
			break;
		}
	}
    fprintf(stderr,"Freedom factor = %d\n", freedom_count);
    if(failed){
        printf("NO SOLUTION\n");
        free(freedom_index);
        return;
    }
	if(freedom_count>0){
		int delta=freedom_count;
		for(k=m-1,t=freedom_count-1;k>=0&&delta>0;k--){
			if(k==freedom_index[t]){
				int i;
				for(i=0;i<m;i++)P[k][i]=0;
				ME[k]=0;
				delta--;t--;
			}else if(delta>0){
				for(i=0;i<m;i++)P[k][i]=P[k-delta][i];
				ME[k]=ME[k-delta];
			}
		}
	}
    //Now ME hold's one solution for X[n],
    //And random reset index inside freedom_index of ME to 0, 1
    //    will result in another solution for X[n];
    //Output one solution
#ifdef _DEBUG
    printf("ME:");vector_output(ME, m);printf("\n");
    printf("H:\n");matrix_output(H,m);
    printf("init:\n");
    matrix_output(init,m);
#endif
    unsigned long long *any_root = (unsigned long long *)malloc(longlong_len*sizeof(unsigned long long));
    unsigned long long *base = (unsigned long long *)malloc(longlong_len *sizeof(unsigned long long) *freedom_count);
//	if(freedom_count>=20)freedom_count=20;//do not search too much, so if the freedom_count is more than 15, the output may not be optimal
	long long u;
	int best_one_count=n*m+1;
	MATRIX bm=matrix_alloc2(n,m);
	for(u=0;u<1LL;u++)//calculate only one roots
    {
        MATRIX x=matrix_alloc2(n,m);
        vector_copy(x[n-1],ME,m);
		for(k=0;k<freedom_count;k++){
			if(u&(1<<k)){
				x[n-1][freedom_index[k]]=1;
				for(i=0;i<m;i++){
					if(P[i][freedom_index[k]]!=0){
						x[n-1][i]^=1;
					}
				}
			}else{
				x[n-1][freedom_index[k]]=0;
			}
		}
        matrix_mul_vector(x[n-2],H,x[n-1],m);
        vector_sum(x[n-2],init[n-1],m);
        for(k=n-3;k>=0;k--){
            H_mul_vector(x[k],x[k+1],m);
#ifdef _DEBUG
            printf("x[%d] 1:",k);vector_output(x[k],m);printf("\n");
#endif
            vector_sum(x[k],init[k+1],m);
#ifdef _DEBUG
            printf("x[%d] 2:",k);vector_output(x[k],m);printf("\n");
#endif
            vector_sum(x[k],x[k+2],m);
#ifdef _DEBUG
            printf("x[%d] 3:",k);vector_output(x[k],m);printf("\n");
#endif
        }
        copy_matrix_to_bit_string(x, m, n, any_root, longlong_len);
        matrix_free(x);
    }
    for(u=0;u<freedom_count;u++){
        MATRIX x=matrix_alloc2(n,m);
        for(k=0;k<m;k++)x[n-1][k]=0;
        x[n-1][freedom_index[u]]=1;//only set one value to bit 1
        for(i=0;i<m;i++){
           if(P[i][freedom_index[u]]!=0){
              x[n-1][i]^=1;
           }
        }
        matrix_mul_vector(x[n-2],H,x[n-1],m);
        for(k=n-3;k>=0;k--){
            H_mul_vector(x[k],x[k+1],m);
            vector_sum(x[k],x[k+2],m);
        }
        copy_matrix_to_bit_string(x, m, n, base+u*longlong_len, longlong_len);
        matrix_free(x);
    }
    search_base_result(any_root, base, freedom_count, longlong_len);
    matrix_free(bm);
    free(freedom_index);
    free(any_root);
    free(base);
}

void parse(int argc, char **argv, int *pn,int *pm){
    if(argc == 2){
        int n = atoi(argv[1]);
        if(n<0||n>N){
            Usage(argv[0]);
        }else if(n<=1){
            printf("%d\n",n);
            exit(0);
        }else{
            init=matrix_alloc(n);
            matrix_init_const(init,1,n,n);
			*pn=*pm=n;
			return;
        }
	}else if(argc==3){
        int n = atoi(argv[1]);
		int m = atoi(argv[2]);
        if(n<0||n>N||m<0||m>N){
            Usage(argv[0]);
        }else if(n<=1||m<=1){
            printf("%d\n",n);
            exit(0);
        }else{
            init=matrix_alloc2(n,m);
            matrix_init_const(init,1,n,m);
			*pn=n;*pm=m;
            return;
        }
	}else{
        int n=argc-1;
        int i,j;
		int m=strlen(argv[1]);
        init=matrix_alloc2(n,m);
        for(i=0;i<n;i++){
            char *s=argv[i+1];
            if(strlen(s)!=m){
                matrix_free(init);
                Usage(argv[0]);
            }
            for(j=0;j<m;j++){
                if(s[j]!='0'&&s[j]!='1'){
                    matrix_free(init);
                    Usage(argv[0]);
                }
                init[i][j]=s[j]-'0';
            }
        }
		*pm=m;*pn=n;
        return;
    }
}

int main(int argc, char **argv){
    int n,m;
    int i;
    MATRIX temp_matrix;
    VECTOR temp_vector;
    if(argc<2){
        Usage(argv[0]);
    }
    parse(argc,argv,&n,&m);
#ifdef _DEBUG
    printf("Input:\n");
    matrix_output2(init,n,m);
#endif
    ME = vector_alloc(m);
    temp_vector = vector_alloc(m);

    P0 = matrix_alloc(m);
    P1 = matrix_alloc(m);
    H  = matrix_alloc(m);
    temp_matrix = matrix_alloc(m);
    matrix_init_H(H,m);
    matrix_init_E(P0,m);
    matrix_init_H(P1,m);
#ifdef _DEBUG
    printf("P(0):\n");matrix_output(P0,m);
    printf("P(1):\n");matrix_output(P1,m);
#endif

    matrix_mul_vector(ME, P0, init[0], m);
    matrix_mul_vector(temp_vector, P1, init[1], m);
#ifdef _DEBUG
    printf("M(0):");vector_output(ME,m);printf("\n");
    printf("M(1):");vector_output(temp_vector,m);printf("\n");
#endif
    vector_sum(ME,temp_vector,m);
#ifdef _DEBUG
    printf("S(1):");vector_output(ME,m);printf("\n");
#endif

    for(i=2;i<=n;i++){
        matrix_mul_H(temp_matrix,P1,m);
        matrix_sum(temp_matrix,P0,m);//P(k)= H*P(k-1) + P(k-2)
        matrix_copy(P0,P1,m);
        matrix_copy(P1,temp_matrix,m);
#ifdef _DEBUG
        printf("P(%d):\n",i);matrix_output(P1,m);
#endif
        if(i<n){
            matrix_mul_vector(temp_vector, P1, init[i], m);
            vector_sum(ME,temp_vector,m);
#ifdef _DEBUG
            printf("M(%d):",i);vector_output(temp_vector,m);printf("\n");
            printf("S(%d):",i);vector_output(ME,m);printf("\n");
#endif
        }
    }

    Solve(P1, ME, n,m);

    matrix_free(init);
    vector_free(ME);
    vector_free(temp_vector);
    matrix_free(P0);
    matrix_free(P1);
    matrix_free(H);
    matrix_free(temp_matrix);
    return 0;
}