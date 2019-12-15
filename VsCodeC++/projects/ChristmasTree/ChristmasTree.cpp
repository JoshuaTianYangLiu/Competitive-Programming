#include <bits/stdc++.h>

using namespace std;
vector<int> g[1000010];
bool visited[1000010];
int main() {
    int v,e;
    scanf("%d %d",&v,&e);
    for(int i=0,a,b; i<e; i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0;
    for(int i=1; i<=v; i++){
        queue<int> q;
        memset(visited,false,sizeof(visited));
        visited[i]=true;
        for(int u:g[i]){
            q.push(u);
            visited[u]=true;
        }
        while(!q.empty()){
            int w=q.front();q.pop();
            for(int u:g[w]){
                if(visited[u]&&u!=i){
                    ans++;
                    // printf("::%d %d\n",w,u);
                }
            }
        }
    }
    printf("%d",ans/6);
    return 0;
}