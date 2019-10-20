#include <bits/stdc++.h>

using namespace std;
int wall[101];
int main() {
    int n,a;
    scanf("%d",&n);
    for(int i=0; i<=n; i++){
        wall[i]=1001;
    }
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){
            scanf("%d",&a);
            int b=i<=n?i:2*n-i+1,c=j<=n?j:2*n-j+1;
            wall[min(b,c)]=min(wall[min(b,c)],a);
            // printf("%d ",min(b,c));
        }
        // printf("\n");
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        ans+=wall[i];
    }
    printf("%d\n",ans);
    return 0;
}
