#include <bits/stdc++.h>

using namespace std;
int in[1000010];
int dp[1000010];
int n;
int solve(int a){
    if(a>=n)return 0;
    if(dp[a]!=-1)return dp[a];
    dp[a]=max(solve(a+in[a]+1)+1,solve(a+1));
    return dp[a];
}
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
    }
    solve(0);
    for(int i=0; i<n; i++){
        printf("%d ",dp[i]);
    }
    printf("\n%d",solve(0));
    return 0;
}