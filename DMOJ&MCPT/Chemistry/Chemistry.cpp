#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    long long n;
    scanf("%lld %d",&n,&m);
    n=pow(n,1.0/m);
    printf("%lld",(long long)ceil(log2(n)));
    return 0;
}