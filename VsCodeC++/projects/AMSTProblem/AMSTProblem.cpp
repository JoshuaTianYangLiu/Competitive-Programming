#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>
bool isVisited[1010];
priority_queue<ii,vector<ii>,greater<ii>> pq;
vector<ii> g[1010];
void p(int n){
    isVisited[n]=true;
    for(ii u:g[n]){
        if(!isVisited[u.first])pq.push({u.second,u.first});
    }
}
int main() {
    memset(isVisited,false,sizeof(isVisited));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    long long ans=0;
    p(1);
    while(!pq.empty()){
        ii u= pq.top();pq.pop();
        if(!isVisited[u.second])ans+=u.first,p(u.second);
    }
    for(int i=1; i<=n; i++){
        if(!isVisited[i]){
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}