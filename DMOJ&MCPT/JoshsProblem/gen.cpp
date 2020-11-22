#include <bits/stdc++.h>

using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

typedef pair<int,int> pi;
int ufds[1000010],rnk[1000010];
void ufdsInit(){memset(rnk,0,sizeof(rnk));for(int i=0; i<1000010; i++)ufds[i]=i;}
int findSet(int i){return ufds[i]==i?i:(ufds[i]=findSet(ufds[i]));}
bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
void unionSet(int i,int j){if(!isSameSet(i,j)){
    int u = findSet(i),v = findSet(j);
    if(rnk[u]>rnk[v])ufds[v]=u;
    else{
        ufds[u]=v;
        if(rnk[u]==rnk[v])rnk[v]++;
    }
}}

int rand(int mod) {
    return (mt()%mod)+1;
}
vector<int> g[1000010];
int tree[1000010];
FILE* file;
void gen_line_tree(int n){
    queue<pair<pi,int>> q;
    ufdsInit();
    int cnt=0;
    for(int i=1; i<=n; i++){
        tree[i]=i;
    }
    for(int i=0; i<1000000; i++){
        int a=rand(n),b=rand(n);
        int tt=tree[a];
        tree[a]=tree[b];
        tree[b]=tt;
    }
    for(int i=1; i<=n/2; i++){
        // int w=rand(100);
        // assert(w>=1&&w<=100);
        q.push({{tree[i],tree[i+1]},1+__builtin_popcount(i-1)%2});
    }
    for(int i=1+n/2; i<n; i++){
        // int w=rand(100);
        // assert(w>=1&&w<=100);
        q.push({{tree[i],tree[i+1]},2-__builtin_popcount(i-1-n/2)%2});
    }
    printf("%d %d %d\n",tree[1],tree[1+n/2],tree[n]);
    assert(q.size()==n-1);
    while(q.size()){
        pair<pi,int> qq=q.front();q.pop();
        g[qq.first.first].push_back(qq.first.second);
        g[qq.first.second].push_back(qq.first.first);
        fprintf(file,"%d %d %d\n",qq.first.first,qq.first.second,qq.second);
    }
}
void gen_tree(int n){
    queue<pair<pi,int>> q;
    ufdsInit();
    int cnt=0;
    for(int i=1; i<n;){
        int u=rand(n),w=rand(100);
        if(cnt>10000){
            for(int j=1; j<=n; j++){
                if(!isSameSet(i,j)){
                    u=j;
                    break;
                }
            }
        }
        assert(u<=n&&u>=1);
        assert(w>=1&&w<=100);
        if(!isSameSet(i,u)){
            cnt=0;
            unionSet(i,u);
            q.push({{i,u},w});
            i++;
        }else{
            cnt++;
        }
    }
    assert(q.size()==n-1);
    while(q.size()){
        pair<pi,int> qq=q.front();q.pop();
        g[qq.first.first].push_back(qq.first.second);
        g[qq.first.second].push_back(qq.first.first);
        fprintf(file,"%d %d %d\n",qq.first.first,qq.first.second,qq.second);
    }

}
vector<int> choices;
vector<int> depth1[100010],depth2[100010];
queue<pi> depthque;
int maxDepth;
int nodes=0;
void dfs(int u,int p,int d,vector<int> dd[]){
    assert(u>=1&&u<=100000);
    assert(p>=1&&p<=100000);
    maxDepth=max(maxDepth,d);
    if(d) dd[d].push_back(u);
    for(int v:g[u]){
        if(v!=p){
            dfs(v,u,d+1,dd);
        }
    }
}
void gen_queries(int n,int q){
    queue<pi> que;
    for(int i=0; i<q; i++){
        if(i%5000==0){
            printf("%d\n",i);
        }
        int a=rand(n),c=rand(n);
        maxDepth=0;
        // printf("First dfs\n");
        dfs(a,a,0,depth1);
        int depthA=maxDepth;
        maxDepth=0;
        dfs(c,c,0,depth2);
        int depthC=maxDepth;
        int len = rand(min(depthA,depthC));

        int ap=rand(depth1[len].size())-1;
        int cp=rand(depth2[len].size())-1;
        int b=depth1[len][ap];
        int d=depth2[len][cp];

        que.push({a,b});
        que.push({c,d});
        // printf("%d %d %d %d %d\n",i,a,b,c,d);
        for(int j=0; j<=depthA; j++){
            depth1[j].clear();
        }
        for(int j=0; j<=depthC; j++){
            depth2[j].clear();
        }
    }
    assert(que.size()==2*q);
    while(que.size()){
        pi qq = que.front();que.pop();
        pi qqq = que.front();que.pop();
        fprintf(file,"%d %d %d %d\n",qq.first,qq.second,qqq.first,qqq.second);
    }
}
int main() {
    int n=1e5-1,q=1e5;
    file=fopen("data.in","w");
    fprintf(file,"%d %d\n",n,q);
    printf("Gerating Tree\n");
    // gen_tree(n);
    gen_line_tree(n);
    printf("Gerating Queries\n");
    gen_queries(n,q);
    fclose(file);
    return 0;
}