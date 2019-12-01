#include <bits/stdc++.h>

using namespace std;
int field[1002];
int n;
int memo[1010][1010][2];
int c(int n,int l,int r){return n==l?1:2;}
int dp(int l,int r,int dpN,int cnt){
    if(cnt==0)return 0;
    if(memo[l][r][c(dpN,l,r)]!=-1)return memo[l][r][c(dpN,l,r)];
    if(l==0)return memo[l][r][c(dpN,l,r)]=abs(field[dpN]-field[r+1])+dp(l,r+1,r+1,cnt-1);
    if(r==n+1)return memo[l][r][c(dpN,l,r)]=abs(field[dpN]-field[l-1])+dp(l-1,r,l-1,cnt-1);
    return memo[l][r][c(dpN,l,r)]=min(abs(field[dpN]-field[l-1])+dp(l-1,r,l-1,cnt-1),abs(field[dpN]-field[r+1])+dp(l,r+1,r+1,cnt-1));
}
int main() {
    memset(memo,-1,sizeof(memo));
    int t,startZ=0;
    scanf("%d %d",&n,&t);
    for(int i=0; i<n; i++){
        scanf("%d",&field[i]);
        if(field[i]<0)startZ++;
    }
    sort(begin(field),begin(field)+n+1);
    printf("%d\n",dp(startZ,startZ,startZ,t));
    return 0;
}