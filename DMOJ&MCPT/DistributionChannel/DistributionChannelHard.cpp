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
int maxEdge[MN][20],secMaxEdge[MN][20],anotherMaxEdge[MN][20];
int logV,timer;
pi combine(int a,int b,int c,int d){
    set<int,greater<int>> s;
    s.insert(a);s.insert(b);s.insert(c);s.insert(d);
    pi ret={-1,-1};
    for(int v:s){
        if(v>ret.first)ret.first=v;
        if(v>ret.second&&v!=ret.first)ret.second=v;
    }
    if(s.size()==1)ret.second=-1;
    return ret;
}
void dfs(int v,int p,int edge){
    tim[v].first=++timer;
    up[v][0]=p;
    maxEdge[v][0]=edge;
    anotherMaxEdge[v][0]=edge;
    secMaxEdge[v][0]=-1;
    for(int i=1; i<=logV; i++){
        up[v][i]=up[up[v][i-1]][i-1];
        // printf("v=%d i=%d up[v][i]=%d up[v][i-1]=%d\n",v,i,up[v][i],up[v][i-1]);
        // printf("v=%d i=%d maxEdge[v][i]=%d maxEdge[up[v][i-1]][i-1]=%d up[v][i-1]=%d\n",v,i,maxEdge[v][i-1],maxEdge[up[v][i-1]][i-1],up[v][i-1]);
        pi hello = combine(maxEdge[up[v][i-1]][i-1],maxEdge[v][i-1],secMaxEdge[up[v][i-1]][i-1],secMaxEdge[v][i-1]);
        maxEdge[v][i]=hello.first;
        secMaxEdge[v][i]=hello.second;
        anotherMaxEdge[v][i]=max(anotherMaxEdge[up[v][i-1]][i-1],anotherMaxEdge[v][i-1]);
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
pi queryMaxEdge(int u,int v){
    int ut=u,vt=v;
    pi maxE={-1,-1};
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[ut][i],v)){
            // printf("ut\t%d %d %d\n",ut,i,up[ut][i]);
            maxE=combine(maxE.first,maxEdge[ut][i],secMaxEdge[ut][i],maxE.second);
            ut=up[ut][i];
        }
    }
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[vt][i],u)){
            // printf("vt\t%d %d %d %d %d\n",vt,i,up[vt][i],maxE,maxEdge[vt][i]);
            maxE=combine(maxE.first,maxEdge[vt][i],secMaxEdge[vt][i],maxE.second);
            vt=up[vt][i];
        }
    }
    if(!isAncestor(vt,u))maxE=combine(maxE.first,maxEdge[vt][0],secMaxEdge[vt][0],maxE.second);
    if(!isAncestor(ut,v))maxE=combine(maxE.first,maxEdge[ut][0],secMaxEdge[ut][0],maxE.second);
    return maxE;
}
int origQueryMaxEdge(int u,int v){
    int ut=u,vt=v;
    int maxE=0;
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[ut][i],v)){
            // printf("ut\t%d %d %d\n",ut,i,up[ut][i]);
            maxE=max(maxE,anotherMaxEdge[ut][i]);
            ut=up[ut][i];
        }
    }
    for(int i=logV; i>=0; i--){
        if(!isAncestor(up[vt][i],u)){
            // printf("vt\t%d %d %d %d %d\n",vt,i,up[vt][i],maxE,anotherMaxEdge[vt][i]);
            maxE=max(maxE,anotherMaxEdge[vt][i]);
            vt=up[vt][i];
        }
    }
    if(!isAncestor(vt,u))maxE=max(maxE,anotherMaxEdge[vt][0]);
    if(!isAncestor(ut,v))maxE=max(maxE,anotherMaxEdge[ut][0]);
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
    int ans=INT_MAX;
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
        int ttt=origQueryMaxEdge(a.first.first,a.first.second);
        if(minCost-ttt+a.second!=minCost)
            ans=min(ans,minCost-ttt+a.second);

        pi tt=queryMaxEdge(a.first.first,a.first.second);
        // int lca = queryLCA(a.first.first,a.first.second);
        // printf("LCA(%d,%d) = %d\n",a.first.first,a.first.second,lca);
        // printf("%d %d %d %d\n",a.first.first,a.first.second,a.second,tt);
        if(minCost-tt.first+a.second!=minCost&&tt.first!=-1)
            ans=min(ans,minCost-tt.first+a.second);
        if(minCost-tt.second+a.second!=minCost&&tt.second!=-1&&minCost-tt.second+a.second>minCost-ttt+a.second)
            ans=min(ans,minCost-tt.second+a.second);
        // printf("::%d %d %d %d %d\n",minCost-tt.first+a.second,tt.first,a.first.first,a.first.second,a.second);
        // printf("::%d %d %d %d %d\n",minCost-tt.second+a.second,tt.second,a.first.first,a.first.second,a.second);
    }
    // for(int i=0,a,b; i<5; i++){
    //     scanf("%d %d",&a,&b);
    //     printf("%d\n",queryLCA(a,b));
    // }
    // printf("%d %d\n",ans,minCost);
    if(ans==INT_MAX)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}