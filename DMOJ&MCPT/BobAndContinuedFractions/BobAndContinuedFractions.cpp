#include <bits/stdc++.h>

using namespace std;
const int MM=1e9+7;
typedef long long ll;
typedef pair<ll,ll> pll;
int in[300030];
ll gcd(ll a , ll b){if(b==0) return a;a%=b;return gcd(b,a);}
pll add(int a,pll b){
    b.first+=a*b.second;
    ll g=gcd(b.first,b.second);
    b.first/=g;
    b.second/=g;
    return b;
}
pll solve(int l,int r){
    pll ret={1,in[r]};
    for(int i=r-1; i>=l; i--){
        ret=add(in[i],ret);
        swap(ret.first,ret.second);
    }
    swap(ret.first,ret.second);
    return ret;
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    int l,r;
    while(q--){
        scanf("%d %d",&l,&r);
        pll ans=solve(l,r);
        printf("%lld %lld\n",ans.first%MM,ans.second%MM);
    }
    return 0;
}