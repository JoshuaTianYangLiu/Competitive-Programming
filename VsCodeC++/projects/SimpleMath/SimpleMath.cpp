#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
pair<int,int> nodes[300001];
bool visited[300001];
vector<pair<int,int>> graph[500001];
int main() {
    memset(visited,false,sizeof(visited));
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n;i++)nodes[i]={1,k};
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    long long finalAns=1;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int ans=k;
            stack<pair<int,int>> s;
            s.push({i,0});
            while(!s.empty()){
                int t=s.top().first; int par=s.top().second;s.pop();
                visited[t]=true;
                for(pair<int,int> g:graph[t]){
                    pair<int,int> h=nodes[g.first];
                    nodes[g.first]={max(h.first,g.second-nodes[t].second),min(g.second-nodes[t].first,h.second)};
                    nodes[t]={max(nodes[t].first,g.second-nodes[g.first].second),min(nodes[t].second,g.second-nodes[g.first].first)};
                    ans=min(ans,max(nodes[g.first].second-max(nodes[g.first].first,1)+1,0));
                    ans=min(ans,max(nodes[t].second-max(nodes[t].first,1)+1,0));
                    if(!visited[g.first])s.push({g.first,t});
                    else if(g.first!=par) ans=min(ans,1);
                }
            }
            finalAns*=ans;
            finalAns%=MM;
        }
    }
    printf("%lld\n",finalAns);
    return 0;
}