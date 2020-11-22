#include <bits/stdc++.h>

using namespace std;
int n,t;
vector<pair<int,int>> skillz[105];
int memo[105][105][105];
int dp(int skill,int level,int time){
    if(skill==n)return 0;
    if(time<=0)return 0;
    if(memo[skill][level][time]!=-1)return memo[skill][level][time];
    if(level<skillz[skill].size()){
        // printf("1: %d %d %d\n",skill,level,time);
        int a=0;
        if(time-skillz[skill][level].first>=0)a = dp(skill,level+1,time-skillz[skill][level].first)+skillz[skill][level].second;  //Do level and check next
        int b = dp(skill+1,0,time); //Next skill and no more level
        // printf("1: %d %d %d %d %d\n",skill,level,time,a,b);
        return memo[skill][level][time]=max(a,b);
    }else{
        // printf("2: %d %d %d %d\n",skill,level,time,skillz[skill].size());
        return dp(skill+1,0,time); //Next skill and no more level
    }
}
int main() {
    memset(memo,-1,sizeof(memo));
    scanf("%d %d",&n,&t);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        for(int j=0,b,c; j<a; j++){
            scanf("%d %d",&b,&c);
            skillz[i].push_back({b,c});
        }
    }
    printf("%d\n",dp(0,0,t));
    return 0;
}
