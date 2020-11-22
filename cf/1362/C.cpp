#include <bits/stdc++.h>

using namespace std;
int cnt(long long a){
    int ret=0;
    while(a){
        ret+=a%2;
        a/=2;
    }
    return ret;
}
int brute(long long n){
    long long ret=0;
    for(long long i=1; i<=n; i++){
        ret+=cnt(i^(i-1));
    }
    return ret;
}
long long calc(long long n){
    if(n==0)return 0;
    return calc(n/2)+n;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",calc(n));
    }
    return 0;
}