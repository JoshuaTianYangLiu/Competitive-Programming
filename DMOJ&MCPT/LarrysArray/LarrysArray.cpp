#include <bits/stdc++.h>

using namespace std;

pair<int,int> in[1000010];
vector<int> vals;

map<int,vector<pair<int,int>>> g;

map<int,bool> visited;
set<int> edges;
set<int> nodes;

void dfs(int u,int p){
    if(visited[u]){
        return;
    }
    visited[u]=true;
    nodes.insert(u);
    for(pair<int,int> v:g[u]){
        edges.insert(v.second);
        if(v.first!=p){
            dfs(v.first,u);
        }
    }
}

int main() {
    set<int> s;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d %d",&in[i].first,&in[i].second);
        int a=in[i].second;
        int b=in[i].first;
        s.insert(in[i].first);
        s.insert(in[i].second);
        g[a].push_back({b,i});
        g[b].push_back({a,i});
        visited[a]=false;
        visited[b]=false;
    }
    for(int i:s)vals.push_back(i);
    for(int i=vals.size()-1; i>=0; i--){
        edges.clear();
        nodes.clear();
        dfs(vals[i],vals[i]);
        int edgenum=edges.size();
        int nodenum=nodes.size();
        if(edgenum>nodenum){
            printf("-1\n");
            return 0;
        }
        if(edgenum==nodenum){
            printf("%d\n",vals[i]);
            return 0;
        }
    }
    return 0;
}