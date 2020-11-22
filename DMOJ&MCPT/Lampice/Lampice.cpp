#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned int ull;
typedef pair<int,int> pi;
const int BB=47,MN=50010;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))


vector<int> g[MN];
ull rtou[MN],utor[MN];
int depth[MN];
ull depthpow[MN];
ull ppow[MN];
int n;
char in[50010];
int par[50010];
int cnt=0;
int depthAtU[2*MN],firstOcc[MN],nodeAtU[2*MN];
int sparse[2*MN][20];
int root;
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
    for(int v:g[u]){
        if(v!=p){
            dfsLCA(v,u,d+1);
            nodeAtU[cnt]=u;
            depthAtU[cnt++]=d;
        }
    }
}
int lca(int u,int v){
    if(firstOcc[u]>firstOcc[v])return nodeAtU[query(firstOcc[v],firstOcc[u])];
    return nodeAtU[query(firstOcc[u],firstOcc[v])];
}
void buildLCA(){
    cnt=1;
    memset(firstOcc,-1,sizeof(firstOcc));
    dfsLCA(1,1,0);
    cnt++;
    buildSparse();
}
void dfsdepth(int u,int p){
    par[u]=p;
    depth[u]=depth[p]+1;
    for(int v:g[u]){
        if(v!=p)
            dfsdepth(v,u);
    }
}
void dfsrtou(int u,int p,ll hash=0){
    rtou[u]=hash;
    for(int v:g[u]){
        if(v!=p)
            dfsrtou(v,u,hash+(in[v]-'a'+1)*(depthpow[v]));
    }
}
void dfsutor(int u,int p,ll hash=0){
    utor[u]=hash;
    for(int v:g[u]){
        if(v!=p)
            dfsutor(v,u,BB*(hash+(in[v]-'a'+1)));
    }
}
int len(int u,int v){
    return abs(depth[u]-depth[v]);
}
void build(){
    ppow[0]=1;
    for(int i=1; i<=n; i++)ppow[i]=ppow[i-1]*BB;
    // printf("Building Lca");
    depth[root]=1;
    dfsdepth(root,0);
    for(int i=0; i<=n; i++){
        depthpow[i]=ppow[depth[i]];
    }
    dfsrtou(root,0,BB*(in[root]-'a'+1));
    dfsutor(root,0,BB*(in[root]-'a'+1));
    buildLCA();
}
int llca;
ull calc(int u,int v){
    llca=lca(u,v);
    ull u_to_root = utor[u]-ppow[len(u,llca)]*utor[llca];
    ull root_to_v = rtou[v]-rtou[par[llca]];
    int u_maxpow=len(u,llca);
    int r_minpow=depth[llca];
    int smallNum=1;
    // printf("%lld\n",rtou[v]);
    // printf("%d %d LCA %d\n",u,v,llca);
    // printf("Len %d\n",len(u,llca));
    // printf("U to Root %lld  Root to U %lld %d %d %d\n",u_to_root,root_to_v,u_maxpow,r_minpow,smallNum);
    if(u_maxpow>=r_minpow){
        root_to_v*=ppow[u_maxpow-r_minpow+1];
        // printf("Multiplied root to u %d\n",u_maxpow-r_minpow+1);
    }else if(u_maxpow+1<r_minpow){
        u_to_root*=ppow[r_minpow-u_maxpow-1];
        // printf("Multiplied u to root %d\n",r_minpow-u_maxpow-1);
        smallNum+=r_minpow-u_maxpow-1;
    }
    ull hhash=u_to_root+root_to_v;
    return hhash*ppow[n-smallNum-1];
}
int main() {
    freopen("lampice.in.2a","r",stdin);
    time__("Solve"){
        scanf("%d",&n);
        scanf("%s",in+1);
        root=1;
        for(int i=1; i<n; i++){
            int a,b;
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        build();
        int ans=1;
        // printf("%lld %lld\n",calc(3,5),calc(5,3));
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                if(calc(i,j)==calc(j,i)){
                    ans=max(ans,depth[i]+depth[j]-depth[llca]-depth[par[llca]]);
                    // printf("::%d %d\n",i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    return 0;
}