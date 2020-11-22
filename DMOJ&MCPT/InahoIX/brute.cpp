#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MM=1e9+7;
int n,z,in[15];
long long dp[1000010];
ll solve(int x){
    if(x<=n)return 1;
    if(dp[x]!=-1)return dp[x];
    ll ret=0;
    for(int i=1; i<=n; i++){
        ret+=in[i-1]*solve(x-i);
        ret%=MM;
    }
    return dp[x]=ret;
}
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&z);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
    }
    printf("%lld\n",solve(z));
    return 0;
}