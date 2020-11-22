#include <bits/stdc++.h>

using namespace std;
int subTreeSize[200020];
int nodes=0;
bool chosen[200020];
vector<pair<int,int>> g[200020];
int level=0;
int paths[1000010],levelEdge[1000010];
int k;
int pathOnCentroid[200020],levelPathOnCentroid[200020];
int diffGraph[200020];
//LCA
int N,K,cnt=0;
int gcd(int a,int b){return a==0?b:gcd(b%a,a);}
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
    if(levelEdge[curCost]<level){
        paths[curCost]=0;
        levelEdge[curCost]=level;
    }
    paths[curCost]++;
    for(pair<int,int> v:g[u]){
        if(v.first!=p&&!chosen[v.first]){
            dfsLen(v.first,u,curCost+v.second,curLen+1);
        }
    }
}
int global_cent,totalPaths=0,directPaths=0,levelTwo=0,global_totalPaths=0;
bool flagflag;
void dfsSolve(int u,int p,int curCost,int curLen){
    if(levelPathOnCentroid[u]!=levelTwo){
        pathOnCentroid[u]=0;
        levelPathOnCentroid[u]=levelTwo;
    }
    if(curCost<=k&&levelEdge[k-curCost]==level){
        pathOnCentroid[u]+=paths[k-curCost];
        totalPaths+=paths[k-curCost];
    }
    if(curCost==k&&flagflag){
        pathOnCentroid[u]++;
        directPaths++;
    }
    for(pair<int,int> v:g[u]){
        if(v.first!=p&&!chosen[v.first]){
            dfsSolve(v.first,u,curCost+v.second,curLen+1);
        }
    }
}
void dfsUpdate(int u,int p){
    if(levelPathOnCentroid[u]==levelTwo)
    diffGraph[u]+=pathOnCentroid[u];
    for(pair<int,int> v1:g[u]){
        int v=v1.first;
        if(v!=p&&!chosen[v]){
            dfsUpdate(v,u);
        }
    }
}
void dfsAdd(int u,int p){
    for(pair<int,int> v1:g[u]){
        int v=v1.first;
        if(v!=p&&!chosen[v]){
            dfsAdd(v,u);
            if(levelPathOnCentroid[u]==levelTwo)
                pathOnCentroid[u]+=pathOnCentroid[v];
        }
    }
}
void solve(int u){
    nodes=0;
    level++;
    flagflag=true;
    dfs(u,u);
    int cent=centroid(u,u);
    global_cent=cent;
    for(pair<int,int> v1:g[cent]){
        if(!chosen[v1.first]){
            dfsSolve(v1.first,cent,v1.second,1);
            dfsLen(v1.first,cent,v1.second,1);
        }
    }
    flagflag=false;
    level++;
    for(int i=g[cent].size()-1; i>=0; i--){
        pair<int,int> v1=g[cent][i];
        if(!chosen[v1.first]){
            dfsSolve(v1.first,cent,v1.second,1);
            dfsLen(v1.first,cent,v1.second,1);
        }
    }
    for(pair<int,int> v1:g[cent]){
        if(!chosen[v1.first]){
            dfsAdd(v1.first,cent);
        }
    }
    diffGraph[cent]+=directPaths+totalPaths/2;
    global_totalPaths+=directPaths+totalPaths/2;
    directPaths=0;
    totalPaths=0;
    for(pair<int,int> v1:g[cent]){
        if(!chosen[v1.first]){
            dfsUpdate(v1.first,cent);
        }
    }
    levelTwo++;
    chosen[cent]=true;
    for(pair<int,int> v1:g[cent]){
        int v=v1.first;
        if(!chosen[v]){
            solve(v);
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
    solve(1);
    dfsAdd(1,0);
    for(int i=1; i<=N; i++){
        // assert(diffGraph[i]!=-1);
        if(diffGraph[i]==0||global_totalPaths==0){
            printf("0 / 1\n");
        }else{
            int t=gcd(diffGraph[i],global_totalPaths);
            printf("%d / %d\n",diffGraph[i]/t,global_totalPaths/t);
        }
    }
    return 0;
}