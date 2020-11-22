#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
bool check(ll k){
    if(k==0)return false;
    ll cnt=0;
    ll nn=n;
    while(nn){
        cnt+=min(k,nn);
        nn-=min(k,nn);
        nn-=nn/10;
    }
    return 2*cnt>=n;
}
int main() {
    scanf("%lld",&n);
    ll l=0,r=n;r
    while(l<=r){
        ll m=(l+r)/2;
        // printf("%d\n",m);
        if(check(m))r=m-1;
        else l=m+1;
    }
    printf("%lld\n",l);

    return 0;
}