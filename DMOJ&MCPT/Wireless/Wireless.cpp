#include <bits/stdc++.h>

using namespace std;
int grid[30001][1001];
        //m     n
        //y     x
int main() {
    memset(grid,0,sizeof(grid));
    int m,n,in;
    scanf("%d %d %d",&m,&n,&in);
    for(int i=0; i<in; i++){
        int x,y,r,b;
        scanf("%d %d %d %d",&x,&y,&r,&b);
        for(int j=max(y-r,1); j<=min(y+r,m); j++){
            float v=sqrt(r*r-(j-y)*(j-y));
            int lp=ceil(x-v),rp=ceil(x+v);
            rp+=v==floor(v)?1:0;
            grid[j][max(lp,1)]+=b;
            if(rp<=n) grid[j][rp]-=b;
            // printf("%d %d\n",lp,rp);
        }
    }
    int ma=-1;
    int ans=0;
    for(int j=1; j<=n; j++){
        for(int i=1; i<=m; i++){
            grid[i][j]+=grid[i][j-1];
            if(grid[i][j]>ma){
                ma=grid[i][j];
                ans=1;
            }else if(grid[i][j]==ma)ans++;
            // printf("%d ",grid[i][j]);
        }
        // printf("\n");
    }
    printf("%d\n%d\n",ma,ans);
    return 0;
}
