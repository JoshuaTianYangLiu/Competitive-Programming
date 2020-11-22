#include <bits/stdc++.h>

using namespace std;
char a[100010],b[100010];
bool dp[100010][30];
bool visited[100010][30];
int n,m,x;
bool solve(int i,int j,int k){
    if(visited[i][k])return 1;
    // printf("::::%d %d %d\n",i,j,k);
    if(k<=x&&j==m){
        dp[i][k]=true;
        return 1;
    }
    if(i>=n)return 1;
    if(j>=m)return 1;
    if(k>=x)return 1;
    // printf("::%d %d %d\n",i,j,k);
    solve(i+1,j,k);
    if(a[i]!=b[j]){
        dp[i][k]=dp[i+1][k];
        visited[i][k]=true;
        return 1;
    }
    int oldi=i;
    while(a[i]==b[j]&&i<n&&j<m){
        i++;j++;
    }
    solve(i,j,k+1);
    dp[oldi][k]=dp[i][k+1]|dp[oldi+1][k];
    visited[oldi][k]=true;
    return 1;
}
int main() {
    scanf("%d\n",&n);
    scanf("%s\n",a);
    scanf("%d\n",&m);
    scanf("%s\n",b);
    scanf("%d",&x);
    solve(0,0,0);
    printf("%s\n",dp[0][0]?"YES":"NO");
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=x; j++){
    //         printf("%d ",dp[i][j]?1:0);
    //     }
    //     printf("\n");
    // }
    return 0;
}