#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int s;
ll T[10010],F[10010];
ll dp[10010];
deque<int> q;
int n;
ll b(int j){
    return dp[j]-s*F[j]-T[j]*F[n]+T[j]*F[j];
}
double slope(int i,int j){
    return (b(i)-b(j))/(double)(F[i]-F[j]);
}
int main() {
    scanf("%d",&n);
    scanf("%d",&s);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld",&T[i],&F[i]);
        T[i]+=T[i-1];
        F[i]+=F[i-1];
    }
    dp[0]=0;
    // dp[1]=(s+T[1])*(F[n]);
    q.push_back(0);
    for(int i=1; i<=n; i++){
        while(q.size()>1&&slope(q[0],q[1])<=T[i]){
            q.pop_front();
        }
        int jj=q[0];
        dp[i]=dp[jj]+(s+T[i]-T[jj])*(F[n]-F[jj]);
        // printf("%lld %d\n",dp[i],jj);
        while(q.size()>1&&slope(q[q.size()-2],q[q.size()-1])>=slope(q[q.size()-1],i)){
            q.pop_back();
        }
        q.push_back(i);
    }
    printf("%lld\n",dp[n]);
    
    return 0;
}