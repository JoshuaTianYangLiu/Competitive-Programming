#include <bits/stdc++.h>

using namespace std;
char in[55][55];
int dx[]={-1,0,0,1},dy[]={0,1,-1,0};
int n,m,numG=0;
bool f(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(in[i][j]=='B'){
                for(int k=0; k<4; k++){
                    // if(i+dx[k]==n&&j+dy[k]==m){
                    //     return false;
                    // }
                    if(in[i+dx[k]][j+dy[k]]=='G'){
                        return false;
                    }
                    if(in[i+dx[k]][j+dy[k]]=='.'){
                        in[i+dx[k]][j+dy[k]]='#';
                    }
                }
            }
            if(in[i][j]=='G')numG++;
        }
    }
    return true;
}
bool visited[55][55];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        numG=0;
        memset(in,0,sizeof(in));
        memset(visited,false,sizeof(visited));
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++){
            scanf("%s",in[i]+1);
        }
        if(f()){
            int cnt=0;
            queue<pair<int,int>> q;
            q.push({n,m});
            visited[n][m]=true;
            while(!q.empty()){
                pair<int,int> u = q.front(); q.pop();

                if(in[u.first][u.second]=='G') cnt++;;
                if(in[u.first][u.second]=='#') continue;
                for(int i=0; i<4; i++){
                    if(u.first+dx[i]>0&&u.first+dx[i]<=n&&u.second+dy[i]>0&&u.second+dy[i]<=m){
                        if(!visited[u.first+dx[i]][u.second+dy[i]]){
                            visited[u.first+dx[i]][u.second+dy[i]]=true;
                            q.push({u.first+dx[i],u.second+dy[i]});
                        }
                    }
                }
            }
            if(cnt==numG)printf("Yes\n");
            else printf("No\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}