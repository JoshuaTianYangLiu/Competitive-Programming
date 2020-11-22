#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll in[22];
int main() {
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=0; i<n; i++){
        scanf("%lld",&in[i]);
        sum+=in[i];
    }
    ll ans=1e18L;
    for(int i=0; i<(1<<n); i++){
        ll a=0;
        for(int j=0; j<n; j++){
            if(((i>>j)&1)==1){
                a+=in[j];
            }
        }
        ans=min(ans,abs(sum-2*a));
    }
    printf("%lld\n",ans);
    return 0;
}