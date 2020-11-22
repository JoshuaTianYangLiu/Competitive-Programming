#include <bits/stdc++.h>

using namespace std;
char in[60][60];
int floodmap[60][60];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int cnt[60][60];
int r,c;
void bfs(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    floodmap[i][j]=0;
    while(q.size()){
        pair<int,int> u=q.front();q.pop();
        for(int i=0; i<4; i++){
            int x=u.first+dx[i];
            int y=u.second+dy[i];
            if(!(x>=1&&x<=r&&y>=1&&y<=c))continue;
            if(in[x][y]=='X')continue;
            if(in[x][y]=='D')continue;
            if(in[x][y]=='S')continue;
            if(floodmap[u.first][u.second]+1<floodmap[x][y]){
                floodmap[x][y]=floodmap[u.first][u.second]+1;
                q.push({x,y});
            }
        }
    }
}
int main() {
    scanf("%d %d",&r,&c);
    pair<int,int> s,d;
    vector<pair<int,int>> flood;
    for(int i=1; i<=r; i++){
        scanf("%s",&in[i][1]);
        for(int j=1; j<=c; j++){
            if(in[i][j]=='*')flood.push_back({i,j});
            if(in[i][j]=='S')s={i,j};
            if(in[i][j]=='D')d={i,j};
        }
    }
    memset(floodmap,0x3f,sizeof(floodmap));
    memset(cnt,0x3f,sizeof(cnt));
    for(pair<int,int> v:flood){
        // printf("::%d %d\n",v.first,v.second);
        bfs(v.first,v.second);
    }
    // for(int i=1; i<=r; i++){
    //     for(int j=1; j<=c; j++){
    //         printf("%d ",floodmap[i][j]);
    //     }
    //     printf("\n");
    // }
    queue<pair<int,int>> q;
    q.push({s.first,s.second});
    cnt[s.first][s.second]=0;
    while(q.size()){
        pair<int,int> u=q.front();q.pop();
        if(u.first==d.first&&u.second==d.second){
            printf("%d\n",cnt[u.first][u.second]);
            return 0;
        }
        for(int i=0; i<4; i++){
            int x=u.first+dx[i];
            int y=u.second+dy[i];
            if(!(x>=1&&x<=r&&y>=1&&y<=c))continue;
            if(in[x][y]=='X')continue;
            if(cnt[u.first][u.second]+1<cnt[x][y]&&cnt[u.first][u.second]+1<floodmap[x][y]){
                cnt[x][y]=cnt[u.first][u.second]+1;
                q.push({x,y});
            }
        }
    }
    printf("KAKTUS\n");
    return 0;
}