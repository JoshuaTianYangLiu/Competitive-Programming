#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
int in[2003];
int dp[2003];
int main() {
    int n,t,q;
    scanf("%d %d %d",&n,&t,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    for(int i=0,a,b,c; i<q; i++){
        memset(dp,0,sizeof(dp));
        scanf("%d %d %d",&a,&b,&c);
        dp[0]=1;
        c-=in[a]+in[b];
        for(int i=a+1; i<b; i++){
            for(int j=in[i]; j<=c; j++){
                if(j-in[i]>=0)dp[j]+=dp[j-in[i]];
            }
        }
        printf("%d\n",dp[c]);
    }

    return 0;
}
