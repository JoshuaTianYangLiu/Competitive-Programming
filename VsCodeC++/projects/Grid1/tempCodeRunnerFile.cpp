#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
int dp[1001][1001];
int main() {
    memset(dp,0,sizeof(dp));
    int n,m;
    dp[1][1]=1;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            char a;
            scanf("%c",&a);
            while(a=='\n')scanf("%c",&a);
            if(a=='.')dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%M;
        }
    }
    printf("%d",dp[m][n]);
    return 0;
}
