#include <bits/stdc++.h>

using namespace std;
long long dp[100010];
pair<int,int> in[110];
int main() {
    int n,w;
    scanf("%d %d",&n,&w);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&b,&a);
        in[i]={a,b};
    }
    for(int i=0;i<n; i++){
        for(int j=w; j>=in[i].first; j--){
            dp[j]=max(dp[j],dp[j-in[i].first]+in[i].second);
        }
    }
    printf("%lld",dp[w]);
    return 0;
}