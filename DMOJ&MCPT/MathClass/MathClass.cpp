#include <bits/stdc++.h>

using namespace std;
#define ll long long
pair<ll,ll> in[510];
bool isSame(pair<ll,ll> n,pair<ll,ll> m,pair<ll,ll> o){
    ll a=n.first,b=n.second,c=m.first,d=m.second,e=o.first,f=o.second;
    return (c-a)*(2*e-a-c)==(b-d)*(2*f-d-b);
}
int main() {
    int n;
    scanf("%d",&n);
    pair<ll,ll> a,b;
    scanf("%lld %lld %lld %lld",&a.first,&a.second,&b.first,&b.second);
    for(int i=0; i<n; i++){
        scanf("%lld %lld",&in[i].first,&in[i].second);
        if(isSame(a,b,in[i])){
            printf("1\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}