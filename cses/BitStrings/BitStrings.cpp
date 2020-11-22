#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

long long fpow(long long x, long long y) {
  return !y?1:((y % 2 ? x : 1) * fpow((x * x) % MOD, y / 2)) % MOD;
}

int main() {
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",fpow(2,n));

    return 0;
}