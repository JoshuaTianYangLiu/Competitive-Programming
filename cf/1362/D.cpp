#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pi;
vector<int> g[500010];
int topic[500010];
int cnt[500010];
bool visited[500010];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    priority_queue<pi,vector<pi>,greater<pi>> q;
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d",&a);
        if(a==1){
            q.push({a,i});
        }
        topic[i]=a;
    }
    queue<int> ans;
    while(!q.empty()){
        pair<int,int> ut=q.top();q.pop();
        // printf("::%d %d\n",ut.first,ut.second);
        int u=ut.second;
        if(visited[u])continue;
        ans.push(u);
        visited[u]=true;
        if(cnt[u]!=topic[u]-1){
            printf("-1\n");
            return 0;
        }
        cnt[u]=topic[u];
        for(int v:g[u]){
            if(!visited[v]){
                if(cnt[v]==cnt[u]-1){
                    cnt[v]=cnt[u];
                    // printf("::%d\n",v);
                    q.push({topic[v],v});
                }else if(cnt[v]<cnt[u]-1){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    while(ans.size()){
        printf("%d ",ans.front());ans.pop();
    }
    return 0;
}