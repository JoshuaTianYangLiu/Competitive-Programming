#include <bits/stdc++.h>

using namespace std;
int in[100010];
int memo[100010][6];
int cnt[100010][6];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(memo,0,sizeof(memo));
        memset(cnt,0,sizeof(cnt));
        int n,k,z;
        scanf("%d %d %d",&n,&k,&z);
        for(int i=1; i<=n; i++)scanf("%d",&in[i]);
        int ans=in[1];
        memo[1][0]=in[1];
        for(int j=2; j<=n; j++){
            memo[j][0]=memo[j-1][0]+in[j];
            cnt[j][0]=cnt[j-1][0]+1;
            if(cnt[j][0]<=k){
                ans=max(ans,memo[j][0]);
            }
        }
        for(int i=1; i<=z; i++){
            for(int j=1; j<n; j++){
                memo[j][i]=max(memo[j-1][i]+in[j],memo[j+1][i-1]+in[j]);
                cnt[j][i]=cnt[j+1][i-1]+1;
                if(cnt[j][i]<=k)ans=max(ans,memo[j][i]);
            }
            memo[n][i]=memo[n-1][i]+in[n];
            cnt[n][i]=cnt[n-1][i];
            if(cnt[n][i]<=k)ans=max(ans,memo[n][i]);

        }
        printf("%d\n",ans);
    }
    return 0;
}