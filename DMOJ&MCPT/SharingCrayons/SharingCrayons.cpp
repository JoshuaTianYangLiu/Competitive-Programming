#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    map<int,int> m;
    m[0]=1;
    long long tot=0,ans=0;
    for(int i=0,a; i<n; i++){
        scanf("%lld",&a);
        tot=(tot+a)%k;
        ans+=m[tot]++;
    }
    printf("%lld",ans);
    return 0;
}
