#include <bits/stdc++.h>

using namespace std;
int ordA[200010],ordB[200010];
int diff[200010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        ordA[a]=i;
    }
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        ordB[a]=i;
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        diff[(ordA[i]-ordB[i]+n)%n]++;
    }
    for(int i=0; i<n; i++){
        ans=max(ans,diff[i]);
    }
    printf("%d\n",ans);
    return 0;
}