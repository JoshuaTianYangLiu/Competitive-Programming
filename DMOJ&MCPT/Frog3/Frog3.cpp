#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll in[200010];
ll dp[200010];
deque<int> q;
double slope(int i,int j){
    return ((dp[i]+in[i]*in[i])-(dp[j]+in[j]*in[j]))/(2.0*(in[i]-in[j]));
}
int main() {
    int n;
    ll c;
    scanf("%d %lld",&n,&c);
    for(int i=1; i<=n; i++)scanf("%lld",&in[i]);
    dp[1]=0ll;
    q.push_back(1);
    for(int i=2; i<=n; i++){
        while(q.size()>1&&slope(q[0],q[1])<=in[i]){
            q.pop_front();
        }
        dp[i]=dp[q[0]]+(in[i]-in[q[0]])*(in[i]-in[q[0]])+c;
        while(q.size()>1&&slope(q[q.size()-2],q[q.size()-1])>=slope(q[q.size()-1],i)){
            q.pop_back();
        }
        q.push_back(i);
    }
    printf("%lld\n",dp[n]);
    return 0;
}