#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

long long fpow(long long x, long long y) {
  return !y?1:((y % 2 ? x : 1) * fpow((x * x) % MOD, y / 2)) % MOD;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(b-a==c-b){
            long long e=b-a;
            printf("%d\n",(a+e*(d-1))%MOD);
        }else{
            assert(b%a==0);
            long long e=b/a;
            printf("%d\n",(a*fpow(e,d-1))%MOD);
        }
    }
    return 0;
}