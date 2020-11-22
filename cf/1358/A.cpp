#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int nm = n%2;
        int ans=m*(n/2);
        int mm = m%2;
        ans+=nm*(m/2);
        ans+=nm*mm;
        printf("%d\n",ans);
    }
    return 0;
}