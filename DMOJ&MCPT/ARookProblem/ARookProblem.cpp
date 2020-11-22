#include <bits/stdc++.h>

using namespace std;
long long fac(int n){
    long long t=1;
    for(int i=1; i<=n; i++)t*=i;
    return t;
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    if(k>n){
        printf("0");
        return 0;
    }
    long long a = fac(n),b=fac(k),c=fac(n-k);
    a/=b;a/=c;
    a*=a;
    a*=fac(k);
    printf("%lld",a);
    return 0;
}