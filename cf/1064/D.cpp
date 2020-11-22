#include <bits/stdc++.h>

using namespace std;
struct ree{
    int r,c,x,y;
};
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
char in[2010][2010];
bool visited[2010][2010];
int main() {
    int n,m,r,c,x,y;
    scanf("%d %d\n%d %d\n%d %d\n",&n,&m,&r,&c,&x,&y);
    for(int i=1; i<=n; i++){
        scanf("%s",in[i]+1);
    }
    queue<ree> q;
    q.push({r,c,x,y});
    visited[r][c]=true;
    int ans=1;
    while(q.size()){
        ree pos = q.front();q.pop();
        // printf("::%d %d %d %d\n",pos.c,pos.r,pos.x,pos.y);
        for(int i=0; i<4; i++){
            if(dx[i]==0){
                int rr=pos.r+dy[i];
                int cc=pos.c;
                while(in[rr][cc]=='.'){
                    if(in[rr][cc]=='.'&&!visited[rr][cc]){
                        if(in[rr][cc-1]=='.'&&!visited[rr][cc-1]){
                            int xx=pos.x-1;
                            int yy=pos.y;
                            if(xx>=0&&yy>=0&&rr>0&&rr<=n&&cc-1>0&&cc-1<=m){
                                q.push({rr,cc-1,xx,yy});
                                visited[rr][cc-1]=true;
                                ans++;
                            }
                        }
                        if(in[rr][cc+1]=='.'&&!visited[rr][cc+1]){
                            int xx=pos.x;
                            int yy=pos.y-1;
                            if(xx>=0&&yy>=0&&rr>0&&rr<=n&&cc+1>0&&cc+1<=m){
                                q.push({rr,cc+1,xx,yy});
                                visited[rr][cc+1]=true;
                                ans++;
                            }
                        }
                        visited[rr][cc]=true;
                        ans++;
                        rr+=dy[i];
                    }else{
                        break;
                    }
                }
            }else{
                int rr=pos.r+dy[i];
                int cc=pos.c+dx[i];
                if(in[rr][cc]=='.'&&!visited[rr][cc]){
                    int xx=pos.x-((dx[i]==-1)?1:0);
                    int yy=pos.y-((dx[i]==1)?1:0);
                    if(xx>=0&&yy>=0&&rr>0&&rr<=n&&cc>0&&cc<=m){
                        q.push({rr,cc,xx,yy});
                        visited[rr][cc]=true;

                        ans++;
                    }
                }
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         printf("%d",visited[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n",ans);
    return 0;
}