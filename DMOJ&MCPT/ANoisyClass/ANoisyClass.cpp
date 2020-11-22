#include <bits/stdc++.h>

using namespace std;
vector<int> g[10001];
int cnt[10001];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        cnt[b]++;
    }
    queue<int> q;
    int ans=n;
    for(int i=1; i<=n; i++){
        if(cnt[i]==0){
            q.push(i);
            ans--;
        }
    }
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int i=0; i<g[a].size(); i++){
            if(--cnt[g[a][i]]==0){
                q.push(g[a][i]);
                ans--;
            }
        }
    }
    if(ans==0) printf("Y");
    else printf("N");
    return 0;
}