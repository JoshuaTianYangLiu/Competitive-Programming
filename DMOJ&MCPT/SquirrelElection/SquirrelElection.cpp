#include <bits/stdc++.h>

using namespace std;
// Classic Knapsack?
pair<int,int> in[5010];
long long memo[5010][5010];
int main() {
    int n,v=0;
    scanf("%d",&n);
    for(int i=1,a,b; i<=n; i++){
        scanf("%d %d",&a,&b);
        in[i]={1+a/2,b};
        v+=b;
    }
    memset(memo,0x3f,sizeof(memo));
    memo[0][0]=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=v; j++){
            if(j-in[i].second>=0) memo[i][j]=min(memo[i-1][j],in[i].first+memo[i-1][j-in[i].second]);
            else memo[i][j]=memo[i-1][j];
            // printf("%d ",memo[i][j]);
        }
        // printf("\n");
    }
    long long ans=4e18;
    for(int i=1; i<=n; i++){
        for(int j=1+v/2; j<=v; j++){
            ans=min(ans,memo[i][j]);
        }
    }
    printf("%lld\n",ans);

    return 0;
}