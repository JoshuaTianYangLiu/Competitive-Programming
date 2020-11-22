#include <bits/stdc++.h>

using namespace std;
int subTreeSize[200020];
int nodes=0;
bool chosen[200020];
vector<pair<int,int>> g[200020];
int level=0,finalAns=-1;
int minCost[1000010],levelEdge[1000010];
int k;
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
void dfsLen(int u,int p,int curCost,int curLen){
    if(curCost>k)return;
    // printf("::DfsLen %d %d %d %d\n",u,p,curCost,curLen);
    if(minCost[curCost]>curLen||levelEdge[curCost]<level){
        // printf("Modified mincost %d\n",level);
        minCost[curCost]=curLen;
        levelEdge[curCost]=level;
    }
    for(pair<int,int> v:g[u]){
        if(v.first!=p&&!chosen[v.first]){
            dfsLen(v.first,u,curCost+v.second,curLen+1);
        }
    }
}
void dfsSolve(int u,int p,int curCost,int curLen){
    // printf("::DfsSolve %d %d %d %d %d %d\n",u,p,curCost,curLen,level,minCost[k-curCost]);
    if(curCost<=k&&levelEdge[k-curCost]==level){
        // printf("Found path %d\n",curLen+minCost[k-curCost]);
        if(curLen+minCost[k-curCost]<finalAns||finalAns==-1){
            // printf("Updated finalAns %d\n",curLen+minCost[k-curCost]);
            finalAns=curLen+minCost[k-curCost];
        }
    }
    if(curCost==k){
        if(curLen<finalAns||finalAns==-1){
            finalAns=curLen;
        }
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
int best_path(int N, int K, int H[][2], int L[]){
    k=K;
    for(int i=0; i<N-1; i++){
        int u=H[i][0],v=H[i][1];
        g[u].push_back({v,L[i]});
        g[v].push_back({u,L[i]});
    }
    solve(0);
    return finalAns;
}

int main() {
    int N,K;
    scanf("%d %d",&N,&K);
    int H[N-1][2],L[N-1];
    for(int i=0,a,b,c; i<N-1; i++){
        scanf("%d %d %d",&a,&b,&c);
        H[i][0]=a;
        H[i][1]=b;
        L[i]=c;
    }
    printf("%d\n",best_path(N,K,H,L));
    return 0;
}