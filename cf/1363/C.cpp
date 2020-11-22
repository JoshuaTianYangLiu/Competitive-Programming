#include <bits/stdc++.h>

using namespace std;
vector<int> g[1010];
int ss[1010];
void dfs(int u,int p){
    ss[u]=1;
    for(int v:g[u]){
        if(v!=p){
            dfs(v,u);
            ss[u]+=ss[v];
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i=1; i<n; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(x,0);
        int cnt=ss[x];
        cnt-=2;
        if(g[x].size()<=1){
            printf("Ayush\n");
            return 0;
        }
        printf("%s\n",cnt%2==1?"Ashish":"Ayush");
    }
    return 0;
}