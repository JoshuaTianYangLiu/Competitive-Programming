#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
vector<int> g[20001];
bool isE[20001],isD[20001];
int cntPaths[20001];
int shrtPath[20001];
bool visited[20001];

int main() {
    memset(isE,true,sizeof(isE));
    memset(isD,true,sizeof(isD));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0,a,b; i<m; i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        isE[b]=false;
        isD[a]=false;
    }
    queue<int> ent,ans2;
    for(int i=0; i<n; i++){
        shrtPath[i]=MM;
        if(isE[i]){
            ent.push(i);
            cntPaths[i]=1;
            shrtPath[i]=1;
        }
    }
    int ans=0;
    while(!ent.empty()){
        int u=ent.front();
        ent.pop();
        for(int v:g[u]){
            cntPaths[v]+=cntPaths[u]%MM;
            cntPaths[v]%=MM;
            shrtPath[v]=min(shrtPath[v],shrtPath[u]+1);
            if(!visited[v])ent.push(v);
            visited[v]=true;
        }
    }
    for(int i=0; i<n; i++){
        if(isD[i]){
            ans+=cntPaths[i];
            ans%=MM;
            ans2.push(shrtPath[i]);
        }
    }
    printf("%d\n",ans);
    while(!ans2.empty()){
        printf("%d ",ans2.front());
        ans2.pop();
    }
    return 0;
}
