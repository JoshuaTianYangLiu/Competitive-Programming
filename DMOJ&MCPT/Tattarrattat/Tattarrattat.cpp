#include <string>
#include <bits/stdc++.h>

using namespace std;

char a[260],b[260];
int sA,sB;
int dp[260][260];
int f(int m,int n){
    if(m==sA||n==sB)return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    int t;
    if(a[m]==b[n])t=f(m+1,n+1)+1;
    else t= max(f(m+1,n),f(m,n+1));
    dp[m][n]=t;
    return t;
}
int main() {
    for(int i=0; i<5; i++){
        memset(dp,-1,sizeof(dp));
        scanf("%s",a);
        sA=sB=strlen(a);
        for(int i=0; i<sB; i++)b[sA-i-1]=a[i];
        printf("%d\n",f(0,0));
    }
}