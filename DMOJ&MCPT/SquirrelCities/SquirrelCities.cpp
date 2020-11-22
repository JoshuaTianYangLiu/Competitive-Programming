#include <bits/stdc++.h>

using namespace std;
const int MN = 1010;
int rnk[1010];
int ufds[1010];
void ufdsInit(){memset(rnk,0,sizeof(rnk));for(int i=0; i<MN; i++)ufds[i]=i;}
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
struct edge{
    int from,to,d,t;
};
vector<edge> in;
int n,m,q,x,y;
bool connected(){
    for(int i=1; i<=n; i++){
        if(!isSameSet(1,i))return false;
    }
    return true;
}
int main() {
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0,a,b,c,d; i<m; i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        in.push_back({a,b,c,d});
    }
    while(q--){
        ufdsInit();
        scanf("%d %d",&x,&y);
        for(edge e:in){
            if(e.d>=x&&e.t<=y){
                unionSet(e.from,e.to);
            }
        }
        if(connected())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}