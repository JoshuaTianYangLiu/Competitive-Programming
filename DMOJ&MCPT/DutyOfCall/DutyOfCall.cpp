#include <bits/stdc++.h>

using namespace std;
vector<int> g[500010];
bool isRTeam[500010];
bool visited[500010];
int numPoint[500010];
int main() {
    int n,r;
    scanf("%d %d",&n,&r);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        for(int j=0,b;j<a; j++){
            scanf("%d",&b);
            g[i].push_back(b);
            numPoint[b]++;
            //Do we need this?
            g[b].push_back(i);
        }
    }
    isRTeam[r]=true;
    visited[r]=true;
    stack<int> s;
    s.push(r);
    while(!s.empty()){
        int v=s.top();s.pop();
        for(int u: g[v]){
            if(!visited[u]){
                isRTeam[u]=!isRTeam[v];
                s.push(u);
                visited[u]=true;
            }
        }
    }
    int rTeam=0,vTeam=0;
    for(int i=1; i<=n; i++){
        if(numPoint[i]==0){
            if(isRTeam[i])rTeam++;
            else vTeam++;
        }
    }
    printf("%d %d\n",rTeam,vTeam);
    return 0;
}