#include <bits/stdc++.h>

using namespace std;
long long in[500010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld",&in[i]);
    sort(begin(in),begin(in)+n);
    long long ans=0;
    long long ans1=0;
    for(int i=0; i<n; i++){
        ans=in[i]-ans;
        printf("%lld %lld\n",in[i],ans);
        ans1=max(ans1,ans);
    }
    printf("%lld",ans1);
    return 0;
}