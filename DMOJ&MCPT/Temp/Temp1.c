#include <stdio.h>

#define MM 1000000007
#define MAX 1000010
long long fac[MAX*2];
long long fmp(long long n,int p){
  if(p==1)return n;
  if(p==0)return 1;
  if(p%2==0)return fmp(((n%MM)*(n%MM)%MM),p/2)%MM;
  return fmp(((n%MM)*(n%MM)%MM),p/2)%MM*n%MM;
}
int calc(int n){
    return (int)((fac[2*n]*fmp((fac[n+1]*fac[n])%MM,MM-2))%MM);
}
int main() {
    fac[0]=1;
    for(int i=1; i<MAX*2;i++){
        fac[i]=(i*fac[i-1])%MM;
    }
    // freopen("1.in","w",stdout);
    // printf("100000\n");
    // srand(time(0));
    // for(int i=0; i<100000; i++){
    //     int n = (int)(rand()*rand()%1000000+1);
    //     printf("%d\n",n);
    // }
    // fclose(stdout);
    // freopen("TestData/input1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        printf("%d\n",calc(a));
    }
    return 0;
}