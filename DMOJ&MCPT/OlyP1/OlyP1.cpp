#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> pii;
char in[1010][1010];
vector<pair<int,int>> people;
bitset<255> sset[1010][1010];
bitset<255> grid[1010][1010];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool visited[1010][1010];
bool f(pii a,pii b){
    return a.first<b.first;
}
int main() {
    int n,m,k,d;
    scanf("%d %d %d %d",&n,&m,&k,&d);
    for(int i=1; i<=m; i++){
        scanf("%s",&in[i][1]);
        for(int j=1; j<=n; j++){
            if(in[i][j]=='P')people.push_back({i,j});
        }
    }
    for(int j=0; j<people.size(); j++){
        pair<int,int> u=people[j];
        for(int i=max(u.first-d,1); i<=min(u.first+d,m); i++){
            sset[i][max(u.second-d,1)].set(j,1);
            sset[i][min(u.second+d+1,n+1)].set(j,1);
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            sset[i][j]^=sset[i][j-1];
        }
    }
    // for(int i=1; i<=m; i++){
    //     for(int j=1; j<=n; j++){
    //         if(in[i][j]=='P') printf("P ");
    //         else printf("%d ",sset[i][j].count());
    //     }
    //     printf("\n");
    // }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,{1,1}});
    grid[1][1]=sset[1][1];
    while(!pq.empty()){
        pii u = pq.top();pq.pop();
        pair<int,int> coord = u.second;
        if(coord.first==m&&coord.second==n){
            printf("%d\n",u.first);
            cout<<grid[coord.first][coord.second].to_string()<<'\n';
            return 0;
        }
        for(int i=0; i<4; i++){
            int y=coord.first+dy[i];
            int x=coord.second+dx[i];
            if(y>=1&&y<=m&&x>=1&&x<=n){
                if(!visited[y][x]){
                    // if(in[y][x]!='P'){
                        // Some kind of case that I'm kinda worried about but I can't find it
                        // Idk if there is some case that breaks it :/
                        grid[y][x]=grid[coord.first][coord.second]|sset[y][x];
                        pq.push({grid[y][x].count(),{y,x}});
                    // }
                }
            }
        }
        visited[coord.first][coord.second]=true;
    }
    return 0;
}