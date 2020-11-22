#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll in[2000100];
ll dp[2000100];
ll L;
deque<int> q;

ll b(ll j,ll k){
    ll ret= dp[j-1]-dp[k-1]
        +j*j-k*k 
        +in[j-1]*in[j-1]-in[k-1]*in[k-1]
        +2*(in[j-1]*L+j*L+j*in[j-1])-2*(in[k-1]*L+k*L+k*in[k-1]);
    // assert(ret>=0);
    return ret;
}
double slope(ll i,ll j){
    return (b(i,j))/(2.0*(in[i-1]+i-in[j-1]-j));
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
    in[0]=0;
    for(int i=1; i<=n; i++){
        scanf("%lld",&in[i]);
        in[i]+=in[i-1];
    }
    dp[1]=(in[1]-L)*(in[1]-L);
    q.push_back(1);
    for(int i=2; i<=n; i++){
        // if(q.size()>1)printf("%d %d %lld %d %.2lf\n",q[0],q[1],in[i],i,slope1(q[0],q[1]));
        // printf("%d %lld %lld %lld\n",q[0],throwaway(i),b(q[0]),-2*(in[q[0]-1]+q[0])*(in[i]+i));
        // printf("::%lld %lld\n",dp[q[0]-1]+(i-q[0]+in[i]-in[q[0]-1]-L)*(i-q[0]+in[i]-in[q[0]-1]-L), throwaway(i)+b(q[0])-2*(in[q[0]-1]+q[0])*(in[i]+i));
        while(q.size()>1&&slope1(q[0],q[1])<=in[i]+i){
            q.pop_front();
        }
        int jj=q[0];
        dp[i]=min(dp[jj-1]+(i-jj+in[i]-in[jj-1]-L)*(i-jj+in[i]-in[jj-1]-L),dp[i-1]+(in[i]-L-in[i-1])*(in[i]-L-in[i-1]));
        // printf("%lld %d\n",dp[i],jj);
        while(q.size()>1&&slope1(q[q.size()-2],q[q.size()-1])>=slope1(q[q.size()-1],i)){
            q.pop_back();
        }
        q.push_back(i);
    }
    printf("%lld\n",dp[n]);
    return 0;
}