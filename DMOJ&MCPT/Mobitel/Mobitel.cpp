#include <bits/stdc++.h>

using namespace std;
int in[310][310];
set<int> memo[310];
int cnt[310];
const int MM=1e9+7;
int main() {
    int r,s,n;
    scanf("%d %d %d",&r,&s,&n);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=s; j++){
            scanf("%d",&in[i][j]);
        }
    }
    memo[1].insert(in[1][1]);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=s; j++){
            cnt[j+1]=((long long)cnt[j+1]+cnt[j])%MM;
            set<int> buf;
            for(int a:memo[j]){
                printf("%d ",a);
            }
            printf("\n::%d\n",cnt[j]);
            for(int a:memo[j]){
                if((long long)a*in[i+1][j]>=n)cnt[j]++;
                else buf.insert(a*in[i+1][j]);
                if((long long)a*in[i][j+1]>=n)cnt[j+1]++;
                else memo[j+1].insert(a*in[i][j+1]);
            }
            cnt[j]%=MM;
            cnt[j+1]%=MM;
            memo[j].clear();
            memo[j]=buf;
        }
        // for(int j=1; j<=s; j++){
        //     printf("%d ",cnt[j]);
        // }
        // printf("\n");
    }
    printf("%d\n",cnt[s]);
    return 0;
}