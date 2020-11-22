#include <bits/stdc++.h>
// #pragma GCC optimize "Ofast"
// #pragma GCC optimize "unroll-loops"
// #pragma GCC optimize "omit-frame-pointer"
// #pragma GCC optimize "prefetch-loop-arrays"
// #pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"


using namespace std;
const int MM = 1e9+7;
const int MAX = 1e5+5;
typedef long long ll;
pair<int,int> ob[3001];
ll fac[2*MAX];
ll ans[3001];
ll fmp(ll n,int p){
    if(p==1)return n;
    if(p==0)return 1;
    if(p%2==0)return fmp(((n%MM)*(n%MM)%MM),p/2)%MM;
    return fmp(((n%MM)*(n%MM)%MM),p/2)%MM*n%MM;
}
ll choose(int n,int k){
    if(k>n)return 0;
    return (fac[n]*fmp((fac[k]*fac[n-k])%MM,MM-2))%MM;
}
ll sub(ll a,ll b){return (MM+a-b)%MM;}
int main() {
    fac[0]=1;
    for(int i=1; i<=2*MAX; i++)fac[i]=(fac[i-1]*i)%MM;
    int h,w,n;
    scanf("%d %d %d",&h,&w,&n);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        ob[i]={a,b};
    }
    sort(begin(ob),begin(ob)+n);
    ob[n]={h,w};
    for(int i=0; i<=n; i++){
        ans[i]=choose(ob[i].first+ob[i].second-2,ob[i].first-1);
        printf("::%d %lld\n",ob[i].first+ob[i].second-2, ans[i]);
        for(int j=0; j<i; j++){
            if(ob[j].first<=ob[i].first&&ob[j].second<=ob[i].second){
                ans[i]-=(ans[j]*choose(ob[i].first-ob[j].first+ob[i].second-ob[j].second,ob[i].first-ob[j].first))%MM;
                if(ans[i]<0)ans[i]+=MM;
            }
        }
    }
    for(int i=0; i<=n; i++){
        printf("::::%lld\n",ans[i]);
    }
    printf("%lld\n",ans[n]);
    return 0;
}