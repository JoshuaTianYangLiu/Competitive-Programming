#include <bits/stdc++.h>

using namespace std;
vector<int> g[100001];
int dp[100001],ts[100001];
int f(int a){
    if(dp[a]!=-1)return dp[a];
    int ans=0;
    for(int v:g[a]){
        ans=max(ans,f(v)+1);
    }
    dp[a]=ans;
    return ans;
}
int main() {
    memset(dp,-1,sizeof(dp));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0,a,b; i<m; i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        ts[b]++;
    }
    queue<int> q;
    int ans=0;
    for(int i=1; i<=n; i++){
        if(ts[i]==0)ans=max(ans,f(i));
    }
    printf("%d",ans);
    return 0;
}
