#include <bits/stdc++.h>

using namespace std;
int diff[100010];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        diff[a]++;
        diff[b+1]--;
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        diff[i]+=diff[i-1];
        diff[i]%=2;
        if(diff[i])ans++;
    }
    printf("%d\n",ans);
    return 0;
}