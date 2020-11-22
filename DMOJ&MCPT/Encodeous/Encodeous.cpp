#include <bits/stdc++.h>

using namespace std;

int main() {
    long long r = (long long)1<<31;
    long long l=-r;
    long long m=(l+r)/2;
    // printf("%lld %lld\n",l,r);
    while(l<=r){
        printf("%lld\n",m);
        char a;
        cin >> a;
        if(a!='u') l=m+1;
        else r=m-1;
        m=(l+r)/2;
    }
    return 0;
}