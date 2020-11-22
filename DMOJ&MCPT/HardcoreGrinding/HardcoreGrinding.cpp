#include <bits/stdc++.h>

using namespace std;
int in[10000001];
int main() {
    int n;
    scanf("%d",&n);
    int ans=0,cnt=0;
    int m=0;
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b); m=max(m,b);
        in[a]++;in[b]--;
    }
    for(int i=0; i<=m; i++){
        cnt+=in[i];
        ans=max(cnt,ans);
    }
    printf("%d",ans);
    return 0;
}
