#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

vector<pi> g[100010];

ll dist[100010];
ll height[100010];
ll heightChange[100010];
int main() {
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
    for(int i=1; i<=n; i++){
        scanf("%lld",&height[i]);
    }
    for(int i=1; i<=m; i++){
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        g[a].push_back({b,t});
        g[b].push_back({a,t});
    }
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({0,1});
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    while(!pq.empty()){
        pi pp=pq.top();pq.pop();
        // printf("%lld %lld\n",pp.first,pp.second);
        int u=pp.second;
        ll d=pp.first;
        if(d>dist[u])continue;
        for(pi v:g[u]){
            if(dist[u]+v.second+abs(x-height[v.first]-v.second)<dist[v.first]&&height[u]>=v.second&&u==1){
                int yee=max(-v.second+x,0ll)-height[v.first];
                if(yee<0){
                    heightChange[v.first]=abs(yee);
                    dist[v.first]=dist[u]+2*v.second+heightChange[v.first];
                }else{
                    dist[v.first]=dist[u]+v.second+yee;
                }
                
                pq.push({dist[v.first],v.first});
            }
            if(dist[u]+v.second+abs(height[u]-height[v.first]-v.second)<dist[v.first]&&height[u]>=v.second&&u!=1){
                int yee=height[u]-height[v.first]-v.second;;
                if(yee<0){
                    heightChange[v.first]=abs(height[u]-height[v.first]-v.second);
                    dist[v.first]=dist[u]+v.second+heightChange[v.first];
                }else{
                    dist[v.first]=dist[u]+v.second-(heightChange[u]-v.second-height[v.first]);
                }
                pq.push({dist[v.first],v.first});
            }
        }
    }
    for(int i=1; i<=n; i++){
        printf("%lld ",dist[i]);
    }
    printf("\n");
    for(int i=1; i<=n; i++){
        printf("%lld ",heightChange[i]);
    }
    printf("\n");
    if(dist[n]==dist[0])printf("-1\n");
    else printf("%lld\n",dist[n]);
    return 0;
}