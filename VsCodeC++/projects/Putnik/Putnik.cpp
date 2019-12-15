#include <bits/stdc++.h>

using namespace std;
int in[1511][1511];
int dp[1511][1511];
int main() {
    int n;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)scanf("%d",&in[i][j]);
    }
    dp[1][1]=0;
    int ans=INT_MAX;
    for(int l=1; l<=n; l++){
        for(int r=1; r<=n; r++){
            if(l!=r||(l==1&&r==1)){
                int cur=max(l,r)+1;
                if(dp[l][cur]!=-1) dp[l][cur]=min(dp[l][r]+in[r][cur],dp[l][cur]);
                else dp[l][cur]=dp[l][r]+in[r][cur];
                if(dp[cur][r]!=-1) dp[cur][r]=min(dp[l][r]+in[cur][l],dp[cur][r]);
                else dp[cur][r]=dp[l][r]+in[cur][l];
                if(cur==n)ans=min(ans,min(dp[l][cur],dp[cur][r]));
            }
        }
    }
    printf("%d",ans);
    return 0;
}