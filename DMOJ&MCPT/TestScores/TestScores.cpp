#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        long long n,a,b,t;
        scanf("%lld %lld %lld %lld",&n,&a,&b,&t);
        long long x=ceil((t+n*b)*1.0/(a+b));
        if(x<=n)printf("%lld\n",x);
        else printf("-1\n");
    }
    return 0;
}
