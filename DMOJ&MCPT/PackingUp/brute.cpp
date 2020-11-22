#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll in[2000100];
ll dp[2000100];
ll L;
deque<int> q;
ll b(ll j){
    return dp[j-1]+j*j+in[j-1]*in[j-1]+2*(in[j-1]*L+j*L+j*in[j-1]);
}
double slope(ll i,ll j){
    return (b(i)-b(j))/(2.0*(in[i-1]+i-in[j-1]-j));
}
double slope1(ll i,ll j){
    return slope(i,j);
}
ll throwaway(ll i){
    return i*i+in[i]*in[i]+L*L+2*(i*in[i]-i*L-in[i]*L);
}
int main() {
    int n;
    
    scanf("%d %lld",&n,&L);
    for(int i=1; i<=n; i++){
        scanf("%lld",&in[i]);
        in[i]+=in[i-1];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    dp[1]=(in[1]-L)*(in[1]-L);
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i]=min(dp[i],dp[j-1]+(i-j+in[i]-in[j-1]-L)*(i-j+in[i]-in[j-1]-L));
            // printf("%d %lld\n",j,dp[j-1]+(i-j+in[i]-in[j-1]-L)*(i-j+in[i]-in[j-1]-L));
        }
        printf("::%lld\n",dp[i]);
    }
    printf("%lld\n",dp[n]);
    return 0;
}