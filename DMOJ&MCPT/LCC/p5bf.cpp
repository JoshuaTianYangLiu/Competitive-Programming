#include <bits/stdc++.h>

using namespace std;
#define MM  998244353
#define ll long long
ll solve(ll n,ll k,ll m){
    long long ans=0;
    // printf("%lld %lld %lld\n",n,k,m);
    for(int i=k*m; i<=n; i++){
        long long ans1=0;
        for(int j=0; j<k; j++){
            if(ans1==0)ans1=i;
            else{
                ans1*=(i-j*m)%MM;
                ans1%=MM;
            }
        }
        ans+=ans1;
        ans%=MM;
    }
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    ll n,k,m;
    while(t--){
        scanf("%lld %lld %lld",&n,&k,&m);
        printf("%lld\n",solve(n,k,m));
    }

    return 0;
}