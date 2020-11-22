#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll in[100010];
ll dp[100010][3];
int backtrack[100010][210];
int n,k;
ll b(int i){
    return dp[i][1]-in[i]*in[n];
}

double slope(int i,int j){
    if(in[i]==in[j]){
        return -1.0e20;
    }
    return (b(i)-b(j))/(double)(-in[i]+in[j]);
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%lld",&in[i]);
        in[i]+=in[i-1];
    }
    for(int i=1; i<=n; i++){
        dp[i][1]=in[i]*(in[n]-in[i]);
    }
    for(int kk=2; kk<=k; kk++){
        deque<int> q;
        // dp[1][2]=(s+T[1])*(F[n]);
        dp[1][2]=-1;
        q.push_back(1);
        for(int i=2; i<=n; i++){
            // if(q.size()>1){
            //     printf("::%d %d\n",q[0],q[1]);
            //     printf("::%.2lf\n",slope(q[0],q[1]));
            // }
            while(q.size()>1&&slope(q[0],q[1])<=in[i]){
                q.pop_front();
            }
            int jj=q[0];
            dp[i][2]=dp[jj][1]+(in[i]-in[jj])*(in[n]-in[i]);
            backtrack[i][kk]=jj;
            // printf("%lld %d\n",dp[i],jj);
            while(q.size()>1&&slope(q[q.size()-2],q[q.size()-1])>=slope(q[q.size()-1],i)){
                q.pop_back();
            }
            q.push_back(i);
        }
        // for(int i=1; i<=n; i++){
        //     printf("%lld ",dp[i][1]);
        // }
        // printf("\n");
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