#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow10(int p){
    ll ret=1;
    while(p){
        ret*=10;
        p--;
    }
    return ret;
}

int ree(ll n){
    int ret=0;
    while(n){
        n/=10;
        ret++;
    }
    return ret;
}

ll brute(ll n){
    ll ans=0;
    for(int i=1; i<=n; i++){
        int a=(int)ree(i)+1;
        if(a%2==1)ans++;
    }
    return ans;
}

int main() {
    ll n;
    scanf("%lld",&n);
    int a = ree(n)+1;
    ll ans=0;
    for(int i=0; i<=17;i+=2){
        ll m =pow10(i);
        ll o = pow10(i+1)-1;
        if(m>n)break;
        if(n<o){
            ans+=n-m+1;
            // printf("Adding %lld\n",n-m+1);
        }else{
            ans+=o-m+1;
            // printf("Adding %lld\n",o-m+1);
        }
    }
    if(n==1000000000000000000L)ans++;
    printf("%lld\n",ans);
    return 0;
}