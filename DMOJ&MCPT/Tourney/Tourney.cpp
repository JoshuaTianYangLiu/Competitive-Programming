#include <bits/stdc++.h>

using namespace std;
int in[1048586];
int tree[4194344];
int size1;
void build(int n,int L,int R){
    if(L==R)tree[n]=L;
    else{
        int M=(L+R)/2;
        build(2*n,L,M);
        build(2*n+1,M+1,R);
        tree[n]=in[tree[2*n]]>in[tree[2*n+1]]?tree[2*n]:tree[2*n+1];
    }
}
void update(int n,int idx,int L,int R){
    if(L==R)tree[n]=L;
    else{
        int M=(L+R)/2;
        if(L<=idx&&idx<=M){
            update(2*n,idx,L,M);
        }else{
            update(2*n+1,idx,M+1,R);
        }
        tree[n]=in[tree[2*n]]>in[tree[2*n+1]]?tree[2*n]:tree[2*n+1];
    }
}
int main() {
    int q;
    scanf("%d %d",&size1,&q);
    for(int i=1;i<=1<<size1; i++){
        scanf("%d",&in[i]);
    }
    build(1,1,1<<size1);
    for(int i=0,b,c;i<q; i++){
        char a;
        scanf("%c",&a);
        while(a==' '||a=='\n')scanf("%c",&a);
        if(a=='R'){
            scanf("%d %d",&b,&c);
            in[b]=c;
            update(1,b,1,1<<size1);
        }else if(a=='W'){
            printf("%d\n",tree[1]);
        }else{
            scanf("%d",&b);
            int L=1,R=1<<size1,n=1,cnt=0;
            while(L!=R){
                if(tree[n]==b)cnt++;
                int M=(L+R)/2;
                if(L<=b&&b<=M){
                    R=M;
                    n=2*n;
                }else{
                    L=M+1;
                    n=2*n+1;
                }
                
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
