#include <bits/stdc++.h>

using namespace std;
vector<int> g[300030];
int parent[300030];
int stackToNode[300030];
vector<pair<pair<int,int>,int>> query;

int up[300030][19],logV,numOfNodes,timer,depth[300030];
pair<int,int> tim[300030];
void dfs(int v,int p){
    tim[v].first=timer++;
    up[v][0]=p;
    for(int i=1; i<=logV; i++)up[v][i]=up[up[v][i-1]][i-1];
    for(int u:g[v]){
        if(u!=p)dfs(u,v);
    }
    tim[v].second=timer++;
}
void build_lca(){
    logV=ceil(log2(numOfNodes));
    dfs(0,0);
}
bool isAncestor(int u,int v){return tim[u].first<=tim[v].first&&tim[u].second>=tim[v].second;}
int lca(int u,int v){
    // printf("%d %d\n",u,v);
    if(isAncestor(u,v))return u;
    // printf("%d %d\n",u,v);
    if(isAncestor(v,u))return v;
    // printf("%d %d\n",u,v);
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
int main() {
    int n;
    char a;
    scanf("%d\n",&n);
    for(int i=1,b,c; i<=n; i++){
        scanf("\n%c",&a);
        if(a=='a'){
            scanf("%d",&b);
            g[stackToNode[b]].push_back(i);
            parent[i]=stackToNode[b];
            stackToNode[i]=i;
            depth[i]=depth[stackToNode[b]]+1;
            numOfNodes++;
        }else if(a=='b'){
            scanf("%d",&b);
            stackToNode[i]=parent[stackToNode[b]];
            query.push_back({{stackToNode[b],0},2});
        }else{
            scanf("%d %d",&b,&c);
            stackToNode[i]=stackToNode[b];
            // printf("::%d %d\n",b,c);
            query.push_back({{stackToNode[b],stackToNode[c]},3});
        }
    }
    build_lca();
    for(pair<pair<int,int>,int> r:query){
        if(r.second==2)printf("%d\n",r.first);
        else printf("%d\n",depth[lca(r.first.first,r.first.second)]);
    }
    return 0;
}