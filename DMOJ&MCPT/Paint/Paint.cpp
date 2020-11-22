#include <bits/stdc++.h>

using namespace std;
#define ll long long
pair<ll,ll> in[200003]; 
ll dp[200003];
bool f(ll n,pair<ll,ll> m){return n<=m.first;};
int main() {
    ll n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1; i<=m; i++){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        in[i]={b,a};
    }
    dp[0]=0;
    in[m+1]={n+1,n+1};
    sort(in+1,in+m+1);
    for(int i=1; i<=m+1; i++){
        int p = upper_bound(in,in+i,in[i].second,f)-in-1;
        dp[i]=min(dp[i-1]+(in[i].first-in[i-1].first),dp[p]+max(in[i].second-in[p].first-1,0LL));
        if(in[i-1].first==in[i].second) dp[i]=dp[p]+max(in[i].second-in[p].first-1,0LL);
        // printf("%lld %lld %lld %lld %lld %lld %d\n",dp[i],in[i].first,in[i].second,in[i-1].first,in[i-1].second,in[p].first,p);
    }
    printf("%lld\n",dp[m+1]);
    return 0;
}
