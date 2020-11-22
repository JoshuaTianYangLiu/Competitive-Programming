#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;
const int MN=(1<<13)+10;
int bit[MN][MN];
void insert(int x,int y1,int l){
    // if(x==0||y1==0)return;
    for(;x<MN;x+=x&-x){
        for(int y=y1;y<MN;y+=y&-y){
            bit[x][y]+=l;
        }
    }
}
int rsq(int x,int y1){
    // if(x<0||y1<0)return 0;
    int n=0;
    for(;x;x-=x&-x){
        for(int y=y1;y;y-=y&-y){
            n+=bit[x][y];
        }
    }
    return n;
}

//a[r]-a[l-1]
//a[x][y]-a[x][w-1]-a[z-1][y]+a[z-1][w-1];
int rsq(int x,int y,int x1,int y1){
    // printf("Query %d %d to %d %d\n",x,y,x1,y1);
    return rsq(x1,y1)-rsq(x1,y-1)-rsq(x-1,y1)+rsq(x-1,y-1);
}
int height[MN];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d",&a);
        insert(i,a+1,1);
        height[i]=a+1;
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         printf("%lld",rsq(i,j));
    //     }
    //     printf("\n");
    // }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b,c,d,e;
        scanf("%d",&a);
        if(a==1){
            scanf("%d %d %d %d",&b,&c,&d,&e);
            printf("%d\n",rsq(b+1,d+1,c+1,e+1));
        }else{
            scanf("%d %d",&b,&c);
            b++;
            insert(b,height[b],-1);
            height[b]=c+1;
            insert(b,c+1,1);
        }
    }
    return 0;
}