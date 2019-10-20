#include <bits/stdc++.h>

using namespace std;
long long bit[251][251][251];
void insert(int x,int y1,int z1,long long l){
    for(;x<251;x+=x&-x){
        for(int y=y1;y<251;y+=y&-y){
            for(int z=z1;z<251;z+=z&-z)bit[x][y][z]+=l;
        }
    }
}
long long rsq(int x,int y1,int z1){
    long long n=0;
    for(;x;x-=x&-x){
        for(int y=y1;y;y-=y&-y){
            for(int z=z1;z;z-=z&-z)n+=bit[x][y][z];
        }
    }
    return n;
}
//a[r]-a[l-1]
//a[x][y]-a[x][w-1]-a[z-1][y]+a[z-1][w-1];
long long rsq(int x,int y,int z,int x1,int y1,int z1){
    return rsq(x1,y1,z1)-rsq(x1,y1,z-1)-rsq(x1,y-1,z1)-rsq(x-1,y1,z1)
        +rsq(x1,y-1,z-1)+rsq(x-1,y1,z-1)+rsq(x-1,y-1,z1)
        -rsq(x-1,y-1,z-1);
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    long long ans=0;
    while(q--){
        char a;
        scanf("%c",&a);
        while(a==' '||a=='\n')scanf("%c",&a);
        if(a=='C'){
            int x,y,z;
            long long l;
            scanf("%d %d %d %lld",&x,&y,&z,&l);
            l-=rsq(x,y,z,x,y,z);
            insert(x,y,z,l);
        }else{
            int b,c,d,e,f,g;
            scanf("%d %d %d %d %d %d",&b,&c,&d,&e,&f,&g);
            ans+=rsq(b,c,d,e,f,g);
        }
    }
    printf("%lld",ans);
    return 0;
}
