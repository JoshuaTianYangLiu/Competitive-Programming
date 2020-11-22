#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int>> pii;
int in[100010];
bool visited[100010][85];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main() {
    memset(in,0,sizeof(in));
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    pair<int,int> s,e;
    scanf("%d %d",&s.first,&s.second);
    scanf("%d %d",&e.first,&e.second);
    if(s==e){
        printf("0\n");
        return 0;
    }
    queue<pii> q;
    visited[s.first][s.second]=true;
    q.push({0,s});
    while(q.size()){
        pii uu=q.front();q.pop();
        int v=uu.first;
        // printf("%d ",v);
        pair<int,int> u=uu.second;
        if(u==e){
            printf("%d\n",v);
            return 0;
        }
        for(int i=0; i<4; i++){
            int x=u.first+dx[i];
            int y=u.second+dy[i];
            if(y==0&&dy[i]==-1){
                x--;
                y=in[x];
            }
            if(y==in[x]+1&&dy[i]==1){
                x++;
                y=1;
            }
            if(y>in[x]&&abs(dx[i])==1){
                y=in[x];
            }
            if(x==0)continue;
            if(x>n)continue;
            if(visited[x][y])continue;
            visited[x][y]=true;
            q.push({v+1,{x,y}});
        }
    }
    return 0;
}