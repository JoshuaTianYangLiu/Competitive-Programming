#include <bits/stdc++.h>

using namespace std;
int in[1010][1010];
bool visited[1010][1010];
bool visitedNum[1000010];
//O(mn*min(m,n))
/*
TLE on last subtask
*/
int main(){
    int n,m;
    scanf("%d %d",&m,&n);
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++)scanf("%d",&in[i][j]);
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        pair<int,int> u=q.front();q.pop();
        int x=u.first,y=u.second;
        if(x==m&&y==n){
            printf("yes\n");
            return 0;
        }
        if(!visitedNum[in[x][y]]){
            visitedNum[in[x][y]]=true;
            for(int i=1; i<=sqrt(in[x][y]); i++){
                if(in[x][y]%i==0){
                    int newX=i,newY=in[x][y]/i;
                    if(newX<=m&&newY<=n&&!visited[newX][newY]){
                        visited[newX][newY]=true;
                        q.push({newX,newY});
                    }
                    if(newX<=n&&newY<=m&&!visited[newY][newX]){
                        visited[newY][newX]=true;
                        q.push({newY,newX});
                    }
                }
            }
        }
    }
    printf("no\n");
    return 0;
}
