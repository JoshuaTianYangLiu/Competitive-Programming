#include <bits/stdc++.h>

using namespace std;
char in[110][1010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x,y;
        scanf("%d %d %d %d",&n,&m,&x,&y);
        long long ans=0;
        for(int i=1; i<=n; i++){
            scanf("%s",in[i]+1);
            for(int j=1; j<=m; j++){
                // printf("::%d\n",j);
                if(j<m&&in[i][j]=='.'&&in[i][j+1]=='.'){
                    ans+=min(y,2*x);
                    j++;
                }else if(in[i][j]=='.'){
                    ans+=x;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}