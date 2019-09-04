#include <bits/stdc++.h>

using namespace std;
#define pi pair<int,int>
vector<pair<int,int>> g[5001];
int city[5001],dij[5001];

int main() {
    memset(city,-1,sizeof(city));
    memset(dij,-1,sizeof(dij));
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=0; i<t; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({c,b}); g[b].push_back({c,a});
    }
    int k;
    scanf("%d",&k);
    for(int i=0,a,b; i<k; i++){
        scanf("%d %d",&a,&b);
        city[a]=b;
    }
    int d,ans=INT_MAX;
    scanf("%d",&d);
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({0,d});
    dij[d]=0;
    if(city[d]!=-1)ans=min(ans,dij[d]+city[d]);
    while(!pq.empty()){
        pi t=pq.top(); pq.pop();
        if(t.first>dij[t.second]&&dij[t.second]!=-1)continue;
        for(pi v:g[t.second]){
            if(v.first+dij[t.second]<dij[v.second]||dij[v.second]==-1){
                dij[v.second]=v.first+dij[t.second];
                if(city[v.second]!=-1)ans=min(ans,dij[v.second]+city[v.second]);
                pq.push({dij[v.second],v.second});
            }
        }
    }
    printf("%d",ans);
    return 0;
}
