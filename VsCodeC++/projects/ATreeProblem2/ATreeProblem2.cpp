#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> g[100010];
bool visited[100010];
bool passed[100010];
long long dist[100010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a,b,c; i<n-1; i++){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int lN=0;
    stack<int> q;
    q.push(1);
    dist[1]=1;
    while(!q.empty()){
        int t=q.top(); q.pop();
        if(dist[t]>dist[lN])lN=t;
        for(pair<int,int> u:g[t]){
            if(dist[u.first]==0){
                q.push(u.first);
                dist[u.first]=dist[t]+u.second;
            }
        }
    }
    long long finalAns=0;
    for(int i=0; i<n; i++){
        printf("%d\n",lN);
        passed[lN]=true;
        memset(visited,false,sizeof(visited));
        q.push(lN);
        dist[lN]=0;
        int ans=0;
        visited[lN]=true;
        while(!q.empty()){
            int t=q.top(); q.pop();
            if(dist[t]>dist[lN]&&!passed[t])lN=t;
            for(pair<int,int> u:g[t]){
                if(!visited[u.first]){
                    q.push(u.first);
                    dist[u.first]=dist[t]+u.second;
                }
                visited[u.first]=true;
            }
        }
        finalAns+=dist[lN];
    }
    printf("%lld",finalAns);
    return 0;
}
