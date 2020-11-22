#include <bits/stdc++.h>

using namespace std;
int in[100010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&in[i]);
    int ans=INT_MAX;
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        ans=min(in[i]/a,ans);
    }
    printf("%d",ans);
    return 0;
}
