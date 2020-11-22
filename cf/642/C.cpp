#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int cnt=0;
        long long ans=0;
        for(int i=1; i<=(n+1)/2; i++){
            int monkey=2*i-1;
            ans+=cnt*(4ll*monkey-4);
            // printf("%d %d\n",cnt,i);
            cnt++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}