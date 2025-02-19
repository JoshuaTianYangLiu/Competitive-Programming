#include <bits/stdc++.h>

using namespace std;
const int MN = 50010,MM=100010;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
pii g[MM];
int n,m,ufds[MN],rnk[MN];
vector<pi> mst[MN];
vector<pii> excludedMst;
bool f(pii a,pii b){return a.second<b.second;}
void ufdsInit(){for(int i=0; i<MN; i++)ufds[i]=i;}
int findSet(int i){return ufds[i]==i?i:(ufds[i]=findSet(ufds[i]));}
bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
void unionSet(int i,int j){if(!isSameSet(i,j)){
    int u = findSet(i),v = findSet(j);
    if(rnk[u]>rnk[v])ufds[v]=u;
    else{
        ufds[u]=v;
        if(rnk[u]==rnk[v])rnk[v]++;
    }
}}
int minCost=0;
void buildMST(){
    sort(g,g+m,f);
    // for(int i=0; i<m; i++){
    //     printf("%d ",g[i].second);
    // }
    // printf("\n");
    ufdsInit();
    for(int i=0; i<m; i++){
        pii e = g[i];
        if(!isSameSet(e.first.first,e.first.second)){
            minCost+=e.second;
            mst[e.first.first].push_back({e.first.second,e.second});
            mst[e.first.second].push_back({e.first.first,e.second});
            unionSet(e.first.first,e.first.second);
            // printf("Node %d to Node %d Edge %d Added to MST\n",e.first.first,e.first.second,e.second);
        }else{
            if(e.first.first!=e.first.second)
                excludedMst.push_back(e);
            // printf("Node %d to Node %d Edge %d Excluded from MST\n",e.first.first,e.first.second,e.second);
        }
    }
}
pi tim[MN],tree[MN];
int up[MN][20];
int maxEdge[MN][20];
int logV,timer;
void dfs(int v,int p,int edge){
    tim[v].first=++timer;
    up[v][0]=p;
    maxEdge[v][0]=edge;
    for(int i=1; i<=logV; i++){
        up[v][i]=up[up[v][i-1]][i-1];
        // printf("v=%d i=%d up[v][i]=%d up[v][i-1]=%d\n",v,i,up[v][i],up[v][i-1]);
        // printf("v=%d i=%d maxEdge[v][i]=%d maxEdge[up[v][i-1]][i-1]=%d up[v][i-1]=%d\n",v,i,maxEdge[v][i-1],maxEdge[up[v][i-1]][i-1],up[v][i-1]);
        maxEdge[v][i]=max(maxEdge[up[v][i-1]][i-1],maxEdge[v][i-1]);
    }
    for(pi u:mst[v]){
        if(u.first!=p){
            // printf("Dfsing to %d with edge %d\n",u.first,u.second);
            dfs(u.first,v,u.second);
        }
    }
    tim[v].second=++timer;
}
bool visited[MN];
void dfs1(int u,int p,int weight){
    visited[u]=true;
    tree[u]={p,weight};
    for(pi v:mst[u]){
        if(v.first!=p){
            // printf("::Dfsing to %d with edge %d\n",v.first,v.second);
            dfs1(v.first,u,v.second);
        }
    }
}
bool isAncestor(int u,int v){
    // printf("%d %d %d %d %d %d\n",u,v,tim[u].first,tim[u].second,tim[v].first,tim[v].second);
    return tim[u].first<=tim[v].first&&tim[u].second>=tim[v].second;
}
void buildLCA(){
    logV=ceil(log2(n));
    for(int i=1; i<=n; i++){
        for(int j=0; j<=logV; j++){
            up[i][j]=n;
        }
    }
    dfs(1,1,0);
}
int queryLCA(int u,int v){
    if(isAncestor(u,v))return u;
    if(isAncestor(v,u))return v;
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[u][i],v))
            u=up[u][i];
    }
    return up[u][0];
}
int queryMaxEdge(int u,int v){
    int ut=u,vt=v;
    int maxE=0;
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[ut][i],v)){
            // printf("ut\t%d %d %d\n",ut,i,up[ut][i]);
            maxE=max(maxE,maxEdge[ut][i]);
            ut=up[ut][i];
        }
    }
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[vt][i],u)){
            // printf("vt\t%d %d %d %d %d\n",vt,i,up[vt][i],maxE,maxEdge[vt][i]);
            maxE=max(maxE,maxEdge[vt][i]);
            vt=up[vt][i];
        }
    }
    if(!isAncestor(vt,u))maxE=max(maxE,maxEdge[vt][0]);
    if(!isAncestor(ut,v))maxE=max(maxE,maxEdge[ut][0]);
    return maxE;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        g[i]={{a,b},c};
    }
    buildMST();
    dfs1(1,1,0);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            printf("-1\n");
            return 0;
        }
    }
    buildLCA();
    // for(int j=0; j<=logV; j++){
    //     for(int i=1; i<=n; i++){
    //         printf("%d ",maxEdge[i][j]);
    //     }
    //     printf("\n");
    // }
    //mincost
    int ans=INT_MAX-13;
    for(pii a:excludedMst){
        // printf("%d %d||%d %d\n",a.first.first,tree[a.first.first].first,a.first.second,tree[a.first.second].first);
        // if(tree[a.first.first].first==a.first.second){
        //     int ans1=minCost-tree[a.first.first].second+a.second;
        //     if(ans1!=minCost)
        //         ans=min(ans,ans1);
        // }
        // if(tree[a.first.second].first==a.first.first){
        //     int ans1=minCost-tree[a.first.second].second+a.second;
        //     if(ans1!=minCost)
        //         ans=min(ans,ans1);
        // }
        int tt=queryMaxEdge(a.first.first,a.first.second);
        // int lca = queryLCA(a.first.first,a.first.second);
        // printf("LCA(%d,%d) = %d\n",a.first.first,a.first.second,lca);
        // printf("%d %d %d %d\n",a.first.first,a.first.second,a.second,tt);
        if(minCost-tt+a.second!=minCost)
            ans=min(ans,minCost-tt+a.second);
        // printf("::%d %d %d %d %d\n",minCost-tt+a.second,tt,a.first.first,a.first.second,a.second);
    }
    // for(int i=0,a,b; i<5; i++){
    //     scanf("%d %d",&a,&b);
    //     printf("%d\n",queryLCA(a,b));
    // }
    // printf("%d %d\n",ans,minCost);
    if(ans==INT_MAX-13)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}