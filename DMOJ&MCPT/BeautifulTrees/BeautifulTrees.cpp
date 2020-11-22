#include <bits/stdc++.h>

using namespace std;
#define ll long long
bool isGood(ll x){
    x=1+4*x;
    ll y=sqrt(x);
    if(y*y==x&&y%2==1)return true;
    else return false;
}
bool isG[100001];
vector<int> g[100001];
int dist[100001];
bool visited[100001];
int dfs(int x){
    int lN=0;
    stack<int> q;
    q.push(x);
    dist[x]=1;
    while(!q.empty()){
        int t=q.top(); q.pop();
        if(dist[t]>dist[lN])lN=t;
        for(int u:g[t]){
            if(dist[u]==0){
                q.push(u);
                dist[u]=dist[t]+1;
            }
        }
    }
    q.push(lN);
    dist[lN]=1;
    int ans=0;
    visited[lN]=true;
    while(!q.empty()){
        int t=q.top(); q.pop();
        if(dist[t]>dist[ans])ans=t;
        for(int u:g[t]){
            if(!visited[u]){
                q.push(u);
                dist[u]=dist[t]+1;
            }
            visited[u]=true;
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        ll a;
        scanf("%lld",&a);
        if(isGood(a))isG[i]=true;
    }
    for(int i=0,a,b; i<n-1; i++){
        scanf("%d %d",&a,&b);
        if(isG[a]&&isG[b]){
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]&&isG[i])dfs(i);
        ans=max(ans,dist[i]);
    }
    printf("%d",ans);
    return 0;
}