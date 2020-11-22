#include <bits/stdc++.h>

using namespace std;

long long calc(long long n){
    return (n-1)*(n+4)*(n*n-3*n+4)/2;
}

int main() {
    long long n;
    scanf("%lld",&n);
    for(long long i=1; i<=n; i++)printf("%lld\n",calc(i));
    return 0;
}