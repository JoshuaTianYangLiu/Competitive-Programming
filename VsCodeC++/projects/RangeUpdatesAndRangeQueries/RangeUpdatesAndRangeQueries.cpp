#include <bits/stdc++.h>

using namespace std;
int in[1000002];
int tree[4000008];
int left1;
void build(int n,int L,int R){
    if(L==R){
        tree[n]=L;
    }else{
        int M=(L+R)/2;
        build(2*n,L,M);
        build(2*n+1,M+1,R);
        tree[n]=tree[2*n]+tree[2*n+1];
    }
}
int diff(int i){return i-left1+1;}
void insert(int n,int idx,int a,int L,int R){
    if(L==R){
        tree[n]+=a*diff(idx);
    }else{
        int M=(L+R)/2;
    }
}
int main() {
    int n,q;
    scanf("%d %d",&q,&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    build(1,1,n);

    return 0;
}
