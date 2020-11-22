#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pi;
int ufds[20020],rnk[20020];
void ufdsInit(){memset(rnk,0,sizeof(rnk));for(int i=0; i<20020; i++)ufds[i]=i;}
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
vector<pi> cobble,road;
bool added[100010];
int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    ufdsInit();
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        if(c){
            road.push_back({a,b});
            unionSet(a,b);
        }
        else cobble.push_back({a,b});
    }
    int cobbleEdges=0,cobbleSz=cobble.size(),roadSz=road.size();
    for(int i=0; i<cobbleSz; i++){
        pi e = cobble[i];
        if(!isSameSet(e.first,e.second)){
            unionSet(e.first,e.second);
            added[i]=true;
            cobbleEdges++;
        }
    }
    if(cobbleEdges>k){
        printf("no solution\n");
        return 0;
    }
    ufdsInit();
    for(int i=0; i<cobbleSz; i++){
        pi e = cobble[i];
        if(added[i])unionSet(e.first,e.second);
    }
    for(int i=0; i<cobbleSz; i++){
        pi e = cobble[i];
        if(!added[i]&&cobbleEdges<k&&!isSameSet(e.first,e.second)){
            unionSet(e.first,e.second);
            added[i]=true;
            cobbleEdges++;
        }
    }
    if(cobbleEdges!=k){
        printf("no solution\n");
        return 0;
    }
    for(int i=0; i<cobbleSz; i++){
        pi e = cobble[i];
        if(added[i]){
            printf("%d %d 0\n",e.first,e.second);
        }
    }
    for(int i=0; i<roadSz; i++){
        pi e = road[i];
        if(!isSameSet(e.first,e.second)){
            unionSet(e.first,e.second);
            printf("%d %d 1\n",e.first,e.second);
        }
    }


    return 0;
}