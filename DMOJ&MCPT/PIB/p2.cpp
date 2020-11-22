#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll t;
bool check(ll p) {
    ll req = p / 2 - p / 7;
    return req <= t;
}

long long fourfec(ll a) {
    t=a;
    ll lo = 0, hi = 1LL << 60, mid, ans = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) ans = max(ans, mid), lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}

long long josh(long long a) {
    int b=0,c=a%5;
    if(c==1)b=2;
    else if(c==2)b=6;
    else if(c==3)b=8;
    else if(c==4)b=10;
    return a/5*14+b+1;
}

int main() {
    long long tv = 1;
    while(true){
        printf("%lld\n",tv);
        if(josh(tv)!=fourfec(tv)){
            printf("%lld %lld %lld\n",tv,josh(tv),fourfec(tv));
            break;
        }
        tv++;
    }
    return 0;
}