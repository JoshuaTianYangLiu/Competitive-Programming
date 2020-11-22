#include <bits/stdc++.h>

using namespace std;
int a[35],b[35];
bool f(int a,int b){return a>b;}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0; i<n; i++)scanf("%d",&a[i]);
        for(int i=0; i<n; i++)scanf("%d",&b[i]);
        sort(begin(a),begin(a)+n);
        sort(begin(b),begin(b)+n,f);
        long long ans=0;
        int i=0;
        for(; i<k&&b[i]>a[i]; i++)ans+=b[i];
        for(; i<n; i++)ans+=a[i];
        printf("%lld\n",ans);
    }
    return 0;
}