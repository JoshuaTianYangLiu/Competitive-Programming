#include <bits/stdc++.h>

using namespace std;
vector<int> g[500010];
int depth[500010];
int endd=0;
void dfs(int u,int p,int d=0){
    depth[u]=d;
    if(depth[u]>depth[endd])endd=u;
    for(int v:g[u]){
        if(v!=p)dfs(v,u,d+1);
    }
}
int ans[500010];
void dfs1(int u,int p,int d=1){
    ans[u]=max(d,ans[u]);
    for(int v:g[u]){
        if(v!=p)dfs1(v,u,d+1);
    }
}
int e,s;
void dia(){
    dfs(1,1);
    e=endd;
    dfs(e,e);
    s=endd;
    dfs1(e,e);
    dfs1(s,s);
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dia();
    for(int i=1; i<=n; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}