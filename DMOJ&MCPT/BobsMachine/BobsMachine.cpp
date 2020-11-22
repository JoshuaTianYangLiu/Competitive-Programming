#include <bits/stdc++.h>

using namespace std;

pair<int,pair<int,int>> in[1010];
bool f(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    if(a.second.second==b.second.second)return a.first>b.first;
    return a.second.first>b.second.first;
}
int dp[1000010];
int ans[1000010];
int lastPos=1000010;
void insert(int i,int v){
    
}
int main() {
    int n,m,r;
    scanf("%d %d %d",&n,&m,&r);
    for(int i=1; i<=m; i++){
        scanf("%d %d %d",&in[i].first,&in[i].second.first,&in[i].second.second);
    }
    sort(begin(in)+1,begin(in)+m+1,f);
    for(int i=1; i<=m; i++){
        printf("%d %d %d\n",in[i].first,in[i].second.first,in[i].second.second);

    }
    return 0;
}