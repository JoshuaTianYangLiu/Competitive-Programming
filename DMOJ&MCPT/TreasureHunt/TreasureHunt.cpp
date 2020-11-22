#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int>> iii;
typedef pair<int,int> ii;
char in[1010][1010];
bool visited[1010][1010];
int y[]={0,1,0,-1},x[]={1,0,-1,0};
int solve(int a,int b){
    memset(visited,false,sizeof(visited));
    priority_queue<iii,vector<iii>,greater<iii>> pq;
    queue<ii> q;
    q.push({a,b});
    int totKeys=0;
    int ret=0;
    while(!q.empty()){
        ii pos = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int pX=pos.first+x[i],pY=pos.second+y[i];
            if(!visited[pX][pY]&&in[pX][pY]!='#'&&in[pX][pY]!=0){
                visited[pX][pY]=true;
                if(in[pX][pY]=='.')q.push({pX,pY});
                else if(in[pX][pY]=='K'){
                    totKeys++;
                    q.push({pX,pY});
                }else if(in[pX][pY]=='T'){
                    ret++;
                    q.push({pX,pY});
                    // printf("\t\t%d %d\n",pX,pY);
                }else if(in[pX][pY]!='S'){
                    pq.push({in[pX][pY]-'0',{pX,pY}});
                }
            }
        }
        while(!pq.empty()&&pq.top().first<=totKeys){
            q.push(pq.top().second);pq.pop();
        }
    }
    return ret;
}
int main() {
    for(int ik=0; ik<10; ik++){
        memset(in,0,sizeof(in));
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%s",&in[i][1]);
        int a,b;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(in[i][j]=='S'){
                    a=i,b=j;
                }
        printf("%d\n",solve(a,b));
    }
    return 0;
}