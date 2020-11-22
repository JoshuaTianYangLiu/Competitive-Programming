#include <bits/stdc++.h>
// #include "secret.h"

using namespace std;
#define ln 2*p
#define rn 2*p+1
int qu[1010][1010];
int in[1010],n,cnt=0;
int Secret(int X,int Y){cnt++; return X*Y;}
void build(int p,int l,int r){
    if(l!=r){
        int m=(l+r)/2;
        for(int i=m-1; i>=l; i--){
            if(qu[i][m]==-1){
                qu[i][m]=Secret(qu[i][i],qu[i+1][m]);
            }
        }
        for(int i=m+2; i<=r; i++){
            if(qu[m+1][i]==-1){
                qu[m+1][i]=Secret(qu[m+1][i-1],qu[i][i]);
            }
        }
        build(ln,l,m);build(rn,m+1,r);
        // seg[p]=Secret(seg[ln],seg[rn]);
    }
}

void Init(int N,int A[]){
    memset(qu,-1,sizeof(qu));
    for(int i=0; i<N; i++){
        in[i+1]=A[i];
        qu[i+1][i+1]=A[i];
    }
    n=N;
    build(1,1,n);
}
int Query(int L,int R){
    L++;R++;
    for(int i=L; i<=R-1; i++){
        if(qu[L][i]!=-1&&qu[i+1][R]!=-1){
            return Secret(qu[L][i],qu[i+1][R]);
        }
    }
    return qu[L][R];
}
int scanIn[1010];
int main() {
    int N,Q;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&scanIn[i]);
    }
    Init(N,scanIn);
    printf("Calls: %d\n",cnt);
    scanf("%d",&Q);
    while(Q--){
        cnt=0;
        int l,r;
        scanf("%d %d",&l,&r);
        printf("Calls: %d %d\n",cnt,Query(l,r));
    }

    return 0;
}