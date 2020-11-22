#include <bits/stdc++.h>

using namespace std;
int in[200020];
int main() {
    int n;
    scanf("%d",&n);
    int mmax=0;
    long long ans=0;
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
        if(in[i]<mmax)ans+=mmax-in[i];
        mmax=max(in[i],mmax);
    }
    printf("%lld\n",ans);
    return 0;
}