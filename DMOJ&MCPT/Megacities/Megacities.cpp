#include <bits/stdc++.h>

using namespace std;
const int MN=100010;
typedef pair<int,pair<int,int>> pii;
int ufds[100010],rnk[100010];
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
bool f(pii a,pii b){return a.second.second<b.second.second;}
vector<pair<int,int>> g[100010];
pii edge[100010];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        edge[i]={a,{b,c}};
    }
    ufdsInit();
    long long ans=0;
    sort(begin(edge),begin(edge)+m,f);
    for(int i=0; i<m; i++){
        pii a = edge[i];
        int u=a.first;
        int v=a.second.first;
        if(!isSameSet(a.first,a.second.first)){
            unionSet(u,v);
            ans+=a.second.second;
        }
    }
    for(int i=1; i<=n; i++){
        if(!isSameSet(1,i)){
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

// (x-n)(x-1)