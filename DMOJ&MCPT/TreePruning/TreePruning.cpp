#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll w[1000010];
vector<int> g[1000010];
void dfsAdd(int u,int p){
    for(int v:g[u]){
        if(v!=p)dfsAdd(v,u);
        w[u]+=w[v];
    }
}
ll ans[1000010];
pair<ll,int> dfsSum(int u,int p,int m){
    pair<ll,int> ret={w[u],1};
    
    for(int v:g[u]){
        if(v!=p&&((1<<(v-1))&m)){
            pair<ll,int> pi=dfsSum(v,u,m);
            ret.first+=pi.first;
            ret.second+=pi.second;
        }
    }
    return ret;
}
int main() {
    int n;
    ll k;
    scanf("%d %lld",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // dfsAdd(1,1);
    for(int i=0; i<=(1<<(n)); i++){
        pair<ll,int> hi={0,0};
        for(int j=0; j<n; j++){
            if(((1<<j)&i)){
                hi=dfsSum(j+1,j+1,i);
                break;
            }
        }
        // printf("::%lld %d\n",hi,i);
        if(k<=hi.first&&hi.first<=2*k&&__builtin_popcount(i)==hi.second){
            printf("%d\n",__builtin_popcount(i));
            for(int j=0; j<n; j++){
                if(((1<<j)&i)){
                    printf("%d ",j+1);
                }
            }
            return 0;
            // printf("\n");
        }
    }
    printf("-1\n");
    return 0;
}