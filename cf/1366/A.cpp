#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,ans=0;
        scanf("%d %d",&a,&b);
        int u = max((2*b-a)/3,0);
        int v = max((2*a-b)/3,0);
        ans+=min(min(u,a),b/2)+min(min(v,a/2),b);
        printf("%d\n",ans);
    }
    return 0;
}