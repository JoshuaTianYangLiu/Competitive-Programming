#include <bits/stdc++.h>

using namespace std;
long long a[300010];
int main() {
    int n,q;
    long long m;
    scanf("%d %lld %d",&n,&m,&q);
    for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
    while(q--){
        int a1,b;
        long long c=m;
        int ans1=0,ans2=0;
        scanf("%d %d",&a1,&b);
        for(int i=a1; i<=b; i++){
            c+=a[i];
            if(c<0)ans2++;
            c=max(0LL,c);
        }
        printf("%lld %d\n",c,ans2);
    }
    return 0;
}