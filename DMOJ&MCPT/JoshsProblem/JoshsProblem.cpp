#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int BB=131,MM=1e9+7,MN=1000010;
vector<pi> g[MN];
ll rtou[MN],utor[MN];
int depth[MN];
ll depthpow[MN];
ll ppow[MN];
int n,q;

void dfsdepth(int u,int p){
    depth[u]=depth[p]+1;
    for(pi v:g[u]){
        if(v.first!=p)
            dfsdepth(v.first,u);
    }
}
void dfsrtou(int u,int p,ll hash=0){
    rtou[u]=hash;
    for(pi v:g[u]){
        if(v.first!=p)
            dfsrtou(v.first,u,(hash+(v.second*depthpow[u])%MM)%MM);
    }
}
void dfsutor(int u,int p,ll hash=0){
    utor[u]=hash;
    for(pi v:g[u]){
        if(v.first!=p)
            dfsutor(v.first,u,(BB*(hash+v.second))%MM);
    }
}
int len(int u,int v){
    return abs(depth[u]-depth[v]);
}
int up[MN][21],logV,timer;
pi tim[MN];
int root=9;
void dfsLca(int v,int p){
    tim[v].first=timer++;
    up[v][0]=p;
    for(int i=1; i<=logV; i++)up[v][i]=up[up[v][i-1]][i-1];
    for(pi u:g[v]){
        if(u.first!=p)dfsLca(u.first,v);
    }
    tim[v].second=timer++;
}
void build_lca(){
    timer=0;
    logV=ceil(log2(n));
    dfsLca(root,root);
}
void build(){
    ppow[0]=1;
    for(int i=1; i<=n; i++)ppow[i]=(ppow[i-1]*BB)%MM;
    // printf("Building Lca");
    dfsdepth(root,root);
    for(int i=1; i<=n; i++){
        depthpow[i]=ppow[depth[i]];
    }
    dfsrtou(root,root);
    dfsutor(root,root);
    // printf("Building LCA");
    build_lca();
}
bool isAncestor(int u,int v){return tim[u].first<=tim[v].first&&tim[u].second>=tim[v].second;}
int lca(int u,int v){
    if(isAncestor(u,v))return u;
    if(isAncestor(v,u))return v;
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
ll calc(int u,int v){
    int llca=lca(u,v);
    ll u_to_root = (MM+utor[u]-(ppow[len(u,llca)]*utor[llca])%MM)%MM;
    ll root_to_v = (rtou[v]-rtou[llca]+MM)%MM;
    int u_maxpow=len(u,llca);
    int r_minpow=depth[llca];
    int smallNum=1;
    // printf("%d %d LCA %d\n",u,v,llca);
    // printf("U to Root %lld  Root to U %lld %d %d %d\n",u_to_root,root_to_v,u_maxpow,r_minpow,smallNum);
    if(u_maxpow>=r_minpow){
        root_to_v*=ppow[u_maxpow-r_minpow+1];
        root_to_v%=MM;
    }else if(u_maxpow+1<r_minpow){
        u_to_root*=ppow[r_minpow-u_maxpow-1];
        u_to_root%=MM;
        smallNum+=r_minpow-u_maxpow-1;
    }
    // printf("U to Root %lld  Root to U %lld %d %d %d\n",u_to_root,root_to_v,u_maxpow,r_minpow,smallNum);
    ll hhash=(u_to_root+root_to_v)%MM;
    // printf("Hash %lld final hash %lld\n\n",hhash,(hhash*ppow[n-smallNum-1])%MM);
    return (hhash*ppow[n-smallNum-1])%MM;
}
int main() {
    freopen("onetwo.in","r",stdin);
    freopen("sol.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1; i<n; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    build();
    while(q--){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(calc(a,b)==calc(c,d))printf("T\n");
        else printf("F\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// Test with match where it's starts at root 