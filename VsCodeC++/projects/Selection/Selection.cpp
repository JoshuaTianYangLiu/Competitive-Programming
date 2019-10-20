#include <bits/stdc++.h>

using namespace std;
int in[300005][21];
int posToRank[300005];
void update(int x,int v,int n){
    for(;x<300005;x+=x&-x)in[x][v]+=n;
}
int query(int x,int v){
    int n=0;
    for(;x;x-=x&-x)n+=in[x][v];
    return n;
}
int rsq(int l,int r, int v){
    return query(r,v)-query(l-1,v);
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        update(i,a,1);
        posToRank[i]=a;
    }
    for(int i=0,a; i<q; i++){
        scanf("%d",&a);
        if(a==1){
            int b,c;
            scanf("%d %d",&b,&c);
            update(b,posToRank[b],-1);
            update(b,c,1);
            posToRank[b]=c;
        }else{
            int b,c,d;
            scanf("%d %d %d",&b,&c,&d);
            for(int i=20; i>=0; i--){
                d-=rsq(b,c,i);
                if(d<1){
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
