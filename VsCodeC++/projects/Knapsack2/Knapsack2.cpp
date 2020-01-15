#include <bits/stdc++.h>

using namespace std;
int dp[100010];
int main() {
    memset(dp,0x3f,sizeof(dp));
    int n,w;
    scanf("%d %d",&n,&w);
    dp[0]=0;
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        for(int j=100001; j>=b; j--){
            dp[j]=min(dp[j],dp[j-b]+a);
        }
    }
    for(int i=100001; i>=0; i--){
        if(dp[i]<=w){
            printf("%d",i);
            break;
        }
    }
    return 0;
}