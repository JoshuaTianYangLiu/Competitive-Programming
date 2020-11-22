#include <bits/stdc++.h>

using namespace std;
int in[200010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d",&in[i]);
        long long ans=0;
        for(int i=0; i<n; i+=2)ans+=in[i];
        long long sr=0,mm=0;
        // o e
        for(int i=1; i<n; i+=2){
            sr+=in[i]-in[i-1];
            mm=max(mm,sr);
            sr=max(sr,0ll);
        }
        sr=0;
        for(int i=1; i<n; i+=2){
            if(i+1>=n)break;
            sr+=in[i]-in[i+1];
            mm=max(mm,sr);
            sr=max(sr,0ll);
        }
        printf("%lld\n",ans+mm);
    }
    return 0;
}