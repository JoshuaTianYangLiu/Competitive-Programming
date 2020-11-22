#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[1000010];
ll pre[1000010];
ll a,b,c;
deque<int> q;
ll intersect(int i){
    return dp[i-1]+a*pre[i-1]*pre[i-1]-b*pre[i-1];
}
double slope(int i,int j){
    return (intersect(i)-intersect(j))/(double)(2*a*(pre[i-1]-pre[j-1]));
}
ll calc(ll i){
    return a*i*i+b*i+c;
}
int main() {
    int n;
    scanf("%d",&n);
    scanf("%lld %lld %lld\n",&a,&b,&c);
    for(int i=1; i<=n; i++){
        scanf("%lld",&pre[i]);
        pre[i]+=pre[i-1];
    }
    dp[1]=a*pre[1]*pre[1]+b*pre[1]+c;
    q.push_back(1);
    for(int i=2; i<=n; i++){
        // if(q.size()>1)printf("%d %d %lld %d %.2lf\n",q[0],q[1],in[i],i,slope1(q[0],q[1]));
        // printf("%d %lld %lld %lld\n",q[0],throwaway(i),b(q[0]),-2*(in[q[0]-1]+q[0])*(in[i]+i));
        // printf("::%lld %lld\n",dp[q[0]-1]+(i-q[0]+in[i]-in[q[0]-1]-L)*(i-q[0]+in[i]-in[q[0]-1]-L), throwaway(i)+b(q[0])-2*(in[q[0]-1]+q[0])*(in[i]+i));
        while(q.size()>1&&slope(q[0],q[1])<=pre[i]){
            q.pop_front();
        }
        int jj=q[0];
        dp[i]=max(dp[jj-1]+calc(pre[i]-pre[jj-1]),dp[i-1]+calc(pre[i]-pre[i-1]));
        // printf("%lld %d\n",dp[i],jj);
        while(q.size()>1&&slope(q[q.size()-2],q[q.size()-1])>=slope(q[q.size()-1],i)){
            q.pop_back();
        }
        q.push_back(i);
    }
    printf("%lld\n",dp[n]);

    return 0;
}