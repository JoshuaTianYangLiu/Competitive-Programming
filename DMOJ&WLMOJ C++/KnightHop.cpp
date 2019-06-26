#include <bits/stdc++.h>

using namespace std;
int kX[]={1,2,2,1,-1,-2,-2,-1};
int kY[]={2,1,-1,-2,-2,-1,1,2};
int board[9][9];
bool bet(int v,int s,int e){
    return v>=s&&v<=e;
}
int main() {
    memset(board,-1,sizeof(board));
    int x,y;
    scanf("%d &d",&x,&y);
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{x,y}});
    while(!q.empty()){
        pair<int,pair<int,int>> t=q.remove();
        pair<int,int> boardCoord=t.second;
        for(int i=0; i<8; i++){
            int bX=boardCoord.first+kX[i];
            int bY=boardCoord.second+kY[i];
            if(bet(bX,1,8)&&bet(bY,1,8)){
                if(board[bX][bY]==-1){
                    q.push({t.first+1,{bX,bY}});
                    board[bX][bY]=t.first+1;
                }
            }
        }
    }
    scanf("%d %d",&x,&y);
    printf("%d",board[x][y]);
    return 0;
}
