#include <bits/stdc++.h>

using namespace std;
long long bit[5002][5002];
void update(int x,int y1,int val){
    if(x==0||y1==0)return;
    for(;x<5002; x+=x&-x){
        for(int y=y1;y<5002;y+=y&-y)bit[x][y]+=val;
    }
}
int query(int x,int y1){
    int n=0;
    for(;x;x-=x&-x){
        for(int y=y1;y;y-=y&-y)n+=bit[x][y];
    }
    return n;
}
int main() {
    int n,q,in,a,b,c,d,e;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf("%d",&in);
        if(in==1){
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
            update(c+1,d+1,e);
            update(a,d+1,-e);
            update(c+1,b,-e);
            update(a,b,e);
        }else{
            scanf("%d %d",&a,&b);
            printf("%d\n",query(a,b));
        }
    }
    return 0;
}
