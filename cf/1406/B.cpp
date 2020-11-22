#include <bits/stdc++.h>

using namespace std;
long long in[100010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        // memset(in,0,sizeof(in));
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%lld",&in[i]);
        sort(in+1,in+n+1);
        long long a=__LONG_LONG_MAX__+1;
        for(int i=0; i<=5; i++){
            long long b=1;
            for(int j=1; j<=i; j++)b*=in[j];
            for(int j=n; j>n-5+i; j--)b*=in[j];
            a=max(a,b);
        }
        printf("%lld\n",a);

    }
    return 0;
}