#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<int,int>> graph[6010];
unordered_map<pair<int,int>,int> m;
bool visited[6010];
void update(int n){
    queue<pair<int,int>> q;
    q.push({n,0});
    visited[n]=true;
    while(!q.empty()){
        pair<int,int> u = q.front(); q.pop();
        for(pair<int,int> v:graph[u.first]){
            if(!visited[v.first]){
                visited[v.first]=true;
                q.push({v.first,u.second+v.second});
                if(m.find({v.first,n})!=m.end())m[{v.first,n}]=u.second+v.second;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a,b,c; i<n-1; i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int q,a,b;
    scanf("%d",&q);
    queue<pair<int,int>> qu;
    while(q--){
        scanf("%d %d",&a,&b);
        qu.push({a,b});
        m[{a,b}]=0;
    }
    for(int i=0; i<n; i++){
        memset(visited,false,sizeof(visited));
        update(i);
    }
    while(!qu.empty()){
        printf("%d\n",m[qu.front()]);qu.pop();
    }

    return 0;
}