#include <bits/stdc++.h>

using namespace std;
typedef pair<long long,long long> pi;
const int MM=1e9+7;
pi in[500010];
bool f(pi a,pi b){return a.first>b.first;}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        long long a,b;
        scanf("%lld %lld",&a,&b);
        in[i]={b,a};
    }
    sort(in+1,in+1+n,f);
    long long ans=0;
    for(int i=1; i<=n; i++){
        ans+=(in[i].second-in[i].first*max(0,i-2))%MM;
        ans=(MM+ans%MM)%MM;
        // printf("%d %d %d\n",in[i].first,in[i].second,in[i].second-in[i].first*max(0,i-2));
    }
    printf("%lld\n",ans);
    return 0;
}