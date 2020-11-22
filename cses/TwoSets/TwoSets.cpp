#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll n;
    scanf("%lld",&n);
    ll m = n*(n+1)/2;
    if(m%2){
        printf("NO\n");
        return 0;
    }
    ll ans=m/2;
    vector<int> a1,a2;
    for(int i=n; i>0; i--){
        if(i<=ans){
            ans-=i;
            a1.push_back(i);
        }else a2.push_back(i);
    }
    printf("YES\n");
    printf("%d\n",a1.size());
    for(int b:a1)printf("%d ",b);
    printf("\n");
    printf("%d\n",a2.size());
    for(int b:a2)printf("%d ",b);
    printf("\n");
    return 0;
}