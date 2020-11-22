#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    scanf("%lld",&n);
    ll five=5,two=2;
    ll a=0,b=0;
    while(five<=n){
        a+=n/five;
        five*=5;
    }
    while(two<=n){
        b+=n/two;
        two*=2;
    }
    printf("%lld\n",min(a,b));
    return 0;
}