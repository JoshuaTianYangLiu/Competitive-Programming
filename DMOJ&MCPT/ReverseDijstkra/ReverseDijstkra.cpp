#include <bits/stdc++.h>

using namespace std;
vector<int> g[19];
bool visited[(1<<19)+2][19];
int main() {
    int n,m,a,b,k;
    scanf("%d %d %d %d %d",&n,&m,&a,&b,&k);
    for(int i=0,x,y; i<m; i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<pair<int,int>> q;
    q.push({a,1<<a});
    visited[1<<a][a];
    int ans=10000;
    int ans2=10000;
    while(!q.empty()){
        int node=q.front().first, vis=q.front().second; q.pop();
        if(node==b){
            int d=abs(k-__builtin_popcount(vis)+1);
            if(d==ans){
                ans2=min(__builtin_popcount(vis)-1,ans2);
            }else if(d<ans){
                ans=min(ans,d);
                ans2=__builtin_popcount(vis)-1;
            }
            continue;
        }
        for(int v:g[node]){
            int t=vis&(1<<v);
            if(t==0&&!visited[vis|(1<<v)][v]){
                q.push({v,vis|(1<<v)});
            }
            visited[vis|(1<<v)][v]=true;
        }
    }
    printf("%d",ans2);
    return 0;
}
