#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
vector<pair<int,int>> g[100010];
ll dist[100010][12];

int k[15];
void solve(int u,int ww){
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    dist[u][ww]=0;
    pq.push({0,u});
    while(pq.size()){
        pl v=pq.top();pq.pop();
        ll d=v.first,u=v.second;
        if(v.first>dist[v.second][ww])continue;
        for(pi a:g[u]){
            if(dist[a.first][ww]>a.second+dist[u][ww]){
                dist[a.first][ww]=a.second+dist[u][ww];
                pq.push({dist[a.first][ww],a.first});
            }
        }
    }
}
int o;
ll f(int u,int mask){
    if(__builtin_popcount(mask)==o+1){
        return dist[0][u];
    }
    ll ans=LONG_MAX;
    for(int i=0; i<=o; i++){
        if(((mask>>i)&1)==0){
            ans=min(ans,dist[k[i]][u]+f(i,mask|(1<<i)));
        }
    }
    return ans;
}
int main() {
    memset(dist,0x3f,sizeof(dist));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    scanf("%d",&o);
    for(int i=1; i<=o; i++)scanf("%d",&k[i]);
    for(int i=0; i<=o; i++){
        solve(k[i],i);
    }
    printf("%lld\n",f(0,1));
    
    return 0;
}