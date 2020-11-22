#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll in[100010];
ll dp[100010][3];
int backtrack[100010][210];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%lld",&in[i]);
        in[i]+=in[i-1];
    }
    for(int i=1; i<=n; i++){
        dp[i][1]=in[i]*(in[n]-in[i]);
        dp[i][2]=-1;
    }
    for(int kk=2; kk<=k; kk++){
        int last=1;
        for(int j=1; j<=n; j++){
            for(int i=last; i<j; i++){
                ll tmp=dp[i][1]+(in[j]-in[i])*(in[n]-in[j]);
                if(tmp>dp[j][2]){
                    dp[j][2]=tmp;
                    last=i;
                    backtrack[j][kk]=i;
                }
            }
        }
        for(int i=1; i<=n; i++){
            dp[i][1]=dp[i][2];
            dp[i][2]=-1;
        }
    }

    ll ans=-1;
    int place;
    for(int i=1; i<=n; i++){
        if(dp[i][1]>ans){
            place=i;
            ans=dp[i][1];
        }
    }
    printf("%lld\n",ans);
    stack<int> s;
    while(k){
        s.push(place);
        place=backtrack[place][k--];
    }
    while(s.size()){
        printf("%d ",s.top());s.pop();
    }
    return 0;
}