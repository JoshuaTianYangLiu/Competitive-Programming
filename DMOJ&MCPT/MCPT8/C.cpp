#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    int ans=0;
    scanf("%lld",&n);
    for(long long i=0; i<n; i++){
        int j=n*n-i*i;

        if(ceil(sqrt(j))==floor(sqrt(j))){
            ans++;
        }
    }
    printf("%d\n",ans*4);
    return 0;
}
