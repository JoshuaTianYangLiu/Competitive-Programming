#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long x,y,k;
        scanf("%lld %lld %lld",&x,&y,&k);
        // n/y=k
        long long b=(k*(y+1)-2+x-1)/(x-1);
        long long n=k+b;
        assert(b*x-b+1>=k*(y+1));
        printf("%lld\n",k+b);
    }
    return 0;
}