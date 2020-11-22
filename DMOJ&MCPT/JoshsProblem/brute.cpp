#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
vector<pi> g[1000010];
vector<int> path1,path2;
bool ree1,ree2;
int a,b,c,d;
void dfs1(int u,int p){
    if(u==b)ree1=true;
    for(pi v: g[u]){
        if(v.first!=p){
            if(!ree1)path1.push_back(v.second);
            dfs1(v.first,u);
            if(!ree1)path1.pop_back();
        }
    }
}
void dfs2(int u,int p){
    if(u==d)ree2=true;
    for(pi v: g[u]){
        if(v.first!=p){
            if(!ree2)path2.push_back(v.second);
            dfs2(v.first,u);
            if(!ree2)path2.pop_back();
        }
    }
}
bool yeet(){
    if(path1.size()!=path2.size()) return false;
    for(int i=0; i<path1.size(); i++){
        if(path1[i]!=path2[i])return false;
    }
    return true;
}
int main() {
    int n,q;
    freopen("data.in","r",stdin);
    // freopen("brute.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1; i<n; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    while(q--){
        ree2=ree1=false;
        path1.clear();
        path2.clear();
        scanf("%d %d %d %d",&a,&b,&c,&d);
        dfs1(a,a);
        dfs2(c,c);
        if(path1.size()!=path2.size()) printf("%d %d\n",path1.size(),path2.size());
        printf("%c\n",yeet()?'T':'F');
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}