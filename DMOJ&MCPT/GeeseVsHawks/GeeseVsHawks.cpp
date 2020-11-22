#include <bits/stdc++.h>

using namespace std;
int n,gp[1010],hp[1010];
char g[1010],h[1010];
int dp[1010][1010];
int main() {
    scanf("%d",&n);
    scanf("%s",g+1);
    for(int i=1; i<=n; i++)scanf("%d",&gp[i]);
    scanf("%s",h+1);
    for(int i=1; i<=n; i++)scanf("%d",&hp[i]);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(gp[i]>hp[j]&&g[i]>h[j]){
                dp[i][j]=max(dp[i][j-1],max(dp[i-1][j-1]+gp[i]+hp[j],dp[i-1][j]));
            }else if(gp[i]<hp[j]&&g[i]<h[j]){
                dp[i][j]=max(dp[i][j-1],max(dp[i-1][j-1]+gp[i]+hp[j],dp[i-1][j]));
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
            // printf("%d ",dp[i][j]);
        }
        // printf("\n");
    }
    printf("%d\n",dp[n][n]);
    return 0;
}