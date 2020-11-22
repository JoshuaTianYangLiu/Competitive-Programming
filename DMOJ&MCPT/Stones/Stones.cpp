#include <bits/stdc++.h>

using namespace std;
int n,k,in[110],dp[100010];
int main() {
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    for(int i=0; i<=k ;i++){
        int hey=0;
        for(int j=1; j<=n; j++){
            if(i-in[j]>=0){
                hey=max(dp[i-in[j]],hey);
            }else{
                hey=max(1,hey);
            }
        }
        dp[i]=hey==1?2:1;
        // printf("%d ",dp[i]);
    }
    printf("%s\n",dp[k]==1?"First":"Second");
    return 0;
}