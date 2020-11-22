#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"


using namespace std;
int subTreeSize[200020];
int nodes=0;
bool chosen[200020];
vector<pair<int,int>> g[200020];
int level=0,finalAns=-1;
int minCost[1000010],levelEdge[1000010];
int k;
vector<int> minCostNode[1000010];

//LCA
int N,K,cnt=0;
int sparse[2*200020][20];
int depthAtU[2*200020],firstOcc[200020],nodeAtU[2*200020];
void buildSparse(){
    for(int i=0; i<cnt; i++)sparse[i][0]=i;
    for(int j=1; (1<<j)<=cnt; j++){
        for(int i=0; i+(1<<j)-1<cnt; i++){
            if(depthAtU[sparse[i][j-1]]<depthAtU[sparse[i+(1<<(j-1))][j-1]])sparse[i][j]=sparse[i][j-1];
            else sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        }
    }
}
int query(int i,int j){
    int k = (int)floor(log2(j-i+1));
    if(depthAtU[sparse[i][k]]<=depthAtU[sparse[j-(1<<k)+1][k]])return sparse[i][k];
    return sparse[j-(1<<k)+1][k];
}
void dfsLCA(int u,int p,int d){
    firstOcc[u]=cnt;
    nodeAtU[cnt]=u;
    depthAtU[cnt++]=d;
    for(pair<int,int> v1:g[u]){
        int v=v1.first;
        if(v!=p){
            dfsLCA(v,u,d+1);
            nodeAtU[cnt]=u;
            depthAtU[cnt++]=d;
        }
    }
}
int lca(int u,int v){
    // printf("lca idx %d %d:%d\n",u,v,query(firstOcc[u],firstOcc[v]));
    if(firstOcc[u]>firstOcc[v])return nodeAtU[query(firstOcc[v],firstOcc[u])];
    return nodeAtU[query(firstOcc[u],firstOcc[v])];
}
void buildLCA(){
    cnt=1;
    memset(firstOcc,-1,sizeof(firstOcc));
    dfsLCA(1,1,0);
    // for(int i=1; i<cnt; i++){printf("%d ",i);}
    // printf("\n");
    // for(int i=1; i<cnt; i++){printf("%d ",firstOcc[i]);}
    // printf("\n");
    // for(int i=1; i<cnt; i++){printf("%d ",nodeAtU[i]);}
    // printf("\n");
    // for(int i=1; i<cnt; i++){printf("%d ",depthAtU[i]);}
    // printf("\n");
    cnt++;
    buildSparse();
}
// I cri //
// pair<int,int> tim[200020];
int parent[200020];
// int up[200020][19],logV,numOfNodes,timer,depth[200020];
int diffGraph[200020];
// void dfsLCA(int u,int p){
//     tim[u].first=timer++;
//     up[u][0]=p;
//     for(int i=1; i<=logV; i++)up[u][i]=up[up[u][i-1]][i-1];
//     for(pair<int,int> v1:g[u]){
//         int v=v1.first;
//         if(v!=p)dfsLCA(v,u);
//     }
//     tim[u].second=timer++;
// }
// void buildLCA(){
//     logV=ceil(log2(N));
//     dfsLCA(1,1);
// }
// bool isAncestor(int u,int v){return tim[u].first<=tim[v].first&&tim[u].second>=tim[v].second;}
// int lca(int u,int v){
//     if(isAncestor(u,v))return u;
//     if(isAncestor(v,u))return v;
//     for(int i=logV; i>=0; i--){
//         if(!isAncestor(up[u][i],v))u=up[u][i];
//     }
//     return up[u][0];
// }
void diffPath(int u,int v){
    // printf("::%d %d %d\n",u,v,lca(u,v));
    diffGraph[u]++;
    diffGraph[v]++;
    diffGraph[lca(u,v)]--;
    diffGraph[parent[lca(u,v)]]--;
}
void dfs(int u,int p){
    subTreeSize[u]=1;
    nodes++;
    for(pair<int,int> v1:g[u]){
        int v=v1.first;
        if(v!=p&&!chosen[v])dfs(v,u),subTreeSize[u]+=subTreeSize[v];
    }
}
int centroid(int u,int p){
    for(pair<int,int> v1:g[u]){
        int v=v1.first;
        if(v!=p&&subTreeSize[v]>nodes/2&&!chosen[v]) return centroid(v,u);
    }
    return u;
}
int minCostNodeStart[2000020];
void dfsLen(int u,int p,int curCost,int curLen){
    if(curCost>k)return;
    // printf("::DfsLen %d %d %d %d\n",u,p,curCost,curLen);
    if(levelEdge[curCost]<level){
        minCost[curCost]=0;
        levelEdge[curCost]=level;
        minCostNodeStart[curCost]=minCostNode[curCost].size();
    }
    minCost[curCost]++;
    minCostNode[curCost].push_back(u);
    // if(minCost[curCost]>curLen||levelEdge[curCost]<level){
    //     // printf("Modified mincost %d\n",level);
    //     minCost[curCost]=curLen;
    //     levelEdge[curCost]=level;
    // }
    for(pair<int,int> v:g[u]){
        if(v.first!=p&&!chosen[v.first]){
            dfsLen(v.first,u,curCost+v.second,curLen+1);
        }
    }
}
int global_cent,totalPaths=0;
void dfsSolve(int u,int p,int curCost,int curLen){
    if(curCost>k)return;
    // printf("::DfsSolve %d %d %d %d\n",u,p,curCost,curLen);
    if(curCost<=k&&levelEdge[k-curCost]==level){
        // printf("Found path %d\n",curLen+minCost[k-curCost]);
        int s=minCostNode[k-curCost].size();
        for(int i=minCostNodeStart[k-curCost]; i<s; i++){
            // printf("Found Path %d %d\n",u,v);
            diffPath(u,minCostNode[k-curCost][i]);
            totalPaths++;
        }
    }
    if(curCost==k){
        // printf("Found Path (global) %d %d\n",u,global_cent);
        diffPath(u,global_cent);
        totalPaths++;
    }
    for(pair<int,int> v:g[u]){
        if(v.first!=p&&!chosen[v.first]){
            dfsSolve(v.first,u,curCost+v.second,curLen+1);
        }
    }
}
// void decompose(int u,int p){
//     nodes=0;
//     dfs(u,u);
//     int centroidNode=centroid(u,u);
//     chosen[centroidNode]=true;
//     cent[p].push_back(centroidNode);
//     cent[centroidNode].push_back(p);
//     for(int v:g[centroidNode]){
//         if(!chosen[v]){
//             decompose(v,centroidNode);
//         }
//     }
// }
void solve(int u){
    nodes=0;
    level++;
    dfs(u,u);
    int cent=centroid(u,u);
    global_cent=cent;
    // printf("Centroid: %d\n",cent);
    for(pair<int,int> v1:g[cent]){
        if(!chosen[v1.first]){
            dfsSolve(v1.first,cent,v1.second,1);
            dfsLen(v1.first,cent,v1.second,1);
        }
    }
    chosen[cent]=true;
    for(pair<int,int> v1:g[cent]){
        int v=v1.first;
        if(!chosen[v]){
            solve(v);
        }
    }
}
void dfsParent(int u,int p){
    parent[u]=p;
    for(pair<int,int> v1:g[u]){
        int v=v1.first;
        if(v!=p)dfsParent(v,u);
    }
}
void dfsAdd(int u,int p){
    for(pair<int,int> v1:g[u]){
        int v=v1.first;
        if(v!=p){
            dfsAdd(v,u);
            diffGraph[u]+=diffGraph[v];
        }
    }
}
int main() {
    /*
    Solve race way (Gen TL prob can memset)
    Lca and diff
    Add
    solve
    */
    scanf("%d %d",&N,&K);
    k=K;
    for(int i=0,a,b,c; i<N-1; i++){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    // dfs(1,0);
    // int cent=centroid(1,0);
    dfsParent(1,0);
    buildLCA();
    solve(1);
    dfsAdd(1,0);
    // for(int i=1; i<=N; i++){
    //     for(int j=0; j<=logV; j++)printf("%d ",up[i][j]);
    //     printf("\n");
    // }
    for(int i=1; i<=N; i++){
        assert(diffGraph[i]!=-1);
        if(diffGraph[i]==0||totalPaths==0){
            printf("0 / 1\n");
        }else{
            int t=__gcd(diffGraph[i],totalPaths);
            printf("%d / %d\n",diffGraph[i]/t,totalPaths/t);
        }
    }
    // printf("%d\n",totalPaths);
    return 0;
}