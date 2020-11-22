#include <bits/stdc++.h>

using namespace std;
int in[505][505];
int main() {
    int n,m;
    scanf("%d %d",&m,&n);
    memset(in,-1,sizeof(in));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&in[i][j]);
            int t=10e9;
            if(in[i-1][j]!=-1&&in[i][j-1]!=-1)in[i][j]+=min(in[i-1][j],in[i][j-1]);
            else if(in[i-1][j]!=-1)in[i][j]+=in[i-1][j];
            else if(in[i][j-1]!=-1)in[i][j]+=in[i][j-1];
        }
    }
    printf("%d",in[m][n]);
    return 0;
}
