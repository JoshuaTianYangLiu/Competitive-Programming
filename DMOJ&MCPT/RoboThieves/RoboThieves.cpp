#include <bits/stdc++.h>

using namespace std;
char grid[101][101];
bool cameraCanSee[101][101];
int robotWalk[101][101];
bool visited[101][101];
pair<int,int> dir[]={{-1,0},{1,0},{0,-1},{0,1}};
int main() {
    memset(robotWalk,-1,sizeof(robotWalk));
    int w,h;
    scanf("%d %d",&w,&h);
    char a;
    pair<int,int> s;
    for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
            scanf("%c",&a);
            while(a=='\n'||a==' ')scanf("%c",&a);
            grid[i][j]=a;
            if(a=='S')s={i,j};
        }
    }
    for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
            if(grid[i][j]=='C'){
                for(int m=i; m>0; m--){
                    if(grid[m][j]=='W')break;
                    if(grid[m][j]=='.'||grid[m][j]=='S')cameraCanSee[m][j]=true;
                }
                for(int m=i; m<=w; m++){
                    if(grid[m][j]=='W')break;
                    if(grid[m][j]=='.'||grid[m][j]=='S')cameraCanSee[m][j]=true;
                }
                for(int m=j; m>0; m--){
                    if(grid[i][m]=='W')break;
                    if(grid[i][m]=='.'||grid[i][m]=='S')cameraCanSee[i][m]=true;
                }
                for(int m=j; m<=h; m++){
                    if(grid[i][m]=='W')break;
                    if(grid[i][m]=='.'||grid[i][m]=='S')cameraCanSee[i][m]=true;
                }
            }
        }
    }
    queue<pair<int,int>> q;
    if(!cameraCanSee[s.first][s.second])q.push(s);
    robotWalk[s.first][s.second]=0;
    while(!q.empty()){
        pair<int,int> t=q.front(); q.pop();
        for(pair<int,int> di:dir){
            di.first+=t.first;
            di.second+=t.second;
            if(di.first>0&&di.first<=w&&di.second>0&&di.second<=h){
                memset(visited,false,sizeof(visited));
                while(true){
                    if(grid[di.first][di.second]!='C'&&grid[di.first][di.second]!='W'&&grid[di.first][di.second]!='S'&&!cameraCanSee[di.first][di.second]){
                        if(grid[di.first][di.second]=='.'){
                            if(robotWalk[di.first][di.second]!=-1)robotWalk[di.first][di.second]=min(robotWalk[di.first][di.second],robotWalk[t.first][t.second]+1);
                            else{
                                robotWalk[di.first][di.second]=robotWalk[t.first][t.second]+1;
                                q.push({di.first,di.second});
                            }
                            break;
                        }else{
                            if(grid[di.first][di.second]=='U')di.first--;
                            else if(grid[di.first][di.second]=='D')di.first++;
                            else if(grid[di.first][di.second]=='L')di.second--;
                            else if(grid[di.first][di.second]=='R')di.second++;
                            if(visited[di.first][di.second])break;
                            visited[di.first][di.second]=true;
                        }                    
                    }else{
                        break;
                    }
                    // printf("\t%d %d",di.first,di.second);
                }
            }
        }
    }
    for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
            if(grid[i][j]=='.'){
                // printf("%d %d\n",cameraCanSee[i][j]?-1:robotWalk[i][j],robotWalk[i][j]);
                printf("%d\n",cameraCanSee[i][j]?-1:robotWalk[i][j]);
            }
        }
        // printf("\n");
    }
    return 0;
}
