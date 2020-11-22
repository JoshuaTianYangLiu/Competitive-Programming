#include <bits/stdc++.h>

using namespace std;
#define IMDUMB 1000000007
char in[110][110];
long long queryTable[110][110];
long long mem[110][110];
int n;
void solve(int m){
    memset(mem,0,sizeof(mem));
    long long ans=0;
    for(int i=m; i<=n; i++){
        ans=0;
        for(int j=1; j<=n; j++){
            if(in[i][j]=='O'){
                mem[i][j]=(mem[i-1][j]+mem[i-1][j-1]+mem[i-1][j+1])%IMDUMB;
                mem[i][j]=max(mem[i][j],1LL);
                ans+=mem[i][j];
                ans%=IMDUMB;
            }
        }
        queryTable[m][i]=ans;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%s",&in[i][1]);
    }
    for(int i=1;i<=n; i++){
        solve(i);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",queryTable[a][b]);
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         printf("%c",in[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}