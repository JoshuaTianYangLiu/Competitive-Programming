#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    long long ans=0;
    int pos=1;
    for(int i=0,a; i<m; i++){
        scanf("%d",&a);
        ans+=(a-pos+n)%n;
        pos=a;
    }
    printf("%lld\n",ans);
    return 0;
}