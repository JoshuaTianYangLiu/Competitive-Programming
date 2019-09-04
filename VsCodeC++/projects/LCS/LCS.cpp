#include <bits/stdc++.h>

using namespace std;
char a[3001],b[3001];
int dp[3001][3001];
char ans[3001];
int main() {
    memset(dp,0,sizeof(dp));
    scanf("%s\n%s",a,b);
    int n=strlen(a),m=strlen(b);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int cnt=dp[n][m];
    int i=n,j=m;
    while(i!=0&&j!=0){
        if(a[i-1]==b[j-1]){
            ans[--cnt]=a[i-1];
            i--;
            j--;
        }else if(dp[i][j]==dp[i-1][j])i--;
        else j--;
    }
    printf("%s",ans);
    return 0;
}
