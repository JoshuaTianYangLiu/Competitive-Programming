#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> g[50010];
int h[50010];   //Im dumb
bool visited[50010];
//0==0 1==1
int main() {
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    while(q--){
        memset(visited,false,sizeof(visited));
        memset(h,0x3f,sizeof(h));
        int a,b;
        scanf("%d %d",&a,&b);
        int ans=0;
        queue<int> q;
        h[a]=0;
        q.push(a);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(pair<int,int> v:g[u]){
                if(!visited[v.first]){
                    visited[v.first]=true;
                    h[v.first]=min(h[v.first],h[u]|v.second);
                    q.push(v.first);
                }
            }
        }
        printf("%d\n",h[b]);
        
    }
    return 0;
}