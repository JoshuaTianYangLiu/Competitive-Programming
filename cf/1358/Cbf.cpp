#include <bits/stdc++.h>

using namespace std;
int grid[1010][1010];
set<int> summ[1010][1010];
int cntt[1010][1010];
int xx1,yy1,xx2,yy2;
void solve(int x,int y,int sum){
    if(x==xx2&&y==yy2){
        cntt[xx2][yy2]++;
        summ[xx2][yy2].insert(sum);
        return;
    }
    if(x<xx2)solve(x+1,y,sum+grid[x+1][y]);
    if(y<yy2)solve(x,y+1,sum+grid[x][y+1]);
}
int main() {
    int cnt=1;
    for(int i=1; i<=1000; i++){
        for(int j=i; j>0; j--){
            grid[i-j+1][j]=cnt++;
        }
    }
    // for(int i=1; i<10; i++){
    //     for(int j=1 ;j<10; j++)printf("%d ",grid[i][j]);
    //     printf("\n");
    // }
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&xx1,&yy1,&xx2,&yy2);
        solve(xx1,yy1,grid[xx1][yy1]);
        printf("%d\n",cntt[xx2][yy2]);
        for(int a:summ[xx2][yy2]){
            printf("%d\n",a);
        }
    }
    return 0;
}