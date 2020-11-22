#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int factors[100010];
int solve(int pos,ll num,int totFac=0){
    if(pos==0)return 0;
    if(num==1&&totFac>1)return 1;
    if(factors[pos]==num&&totFac>0)return 1;
    int ret=0;
    if(num%factors[pos]==0){
        ret=max(solve(pos,num/factors[pos],totFac+1),solve(pos-1,num/factors[pos],totFac+1));
        if(ret==1)return ret;
    }
    ret=max(ret,solve(pos-1,num,totFac));
    return ret;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&factors[i]);
    sort(begin(factors)+1,begin(factors)+1+n);
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        ll a;
        scanf("%lld",&a);
        printf("%d",solve(n,a));
    }
    return 0;
}