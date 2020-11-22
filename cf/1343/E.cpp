#include <bits/stdc++.h>

using namespace std;
int p[200020];
vector<int> g[200020];
bool visited[200020];
vector<int> cnt[200020];
int cnt1[200020];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a,b,c;
        scanf("%d %d %d %d %d",&n,&m,&a,&b,&c);
        for(int i=0; i<m; i++)scanf("%d",&p[i]);
        sort(begin(p),begin(p)+m);
        for(int i=0,u,v; i<m; i++){
            scanf("%d %d",&u,&v);
            g[v].push_back(u);
            g[u].push_back(v);
            cnt[v].push_back(0);
            cnt[u].push_back(0);
        }
        queue<int> q;
        q.push(a);
        visited[a]=true;
        while(q.size()){
            int u = q.front();q.pop();
            for(int i=0; i<g[u].size(); i++){
                int v=g[u][i];
                if(!visited[v]){
                    cnt[u][i]++;
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        memset(visited,false,sizeof(visited));

    }
    return 0;
}