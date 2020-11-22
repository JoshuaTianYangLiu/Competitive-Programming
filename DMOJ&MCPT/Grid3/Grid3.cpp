#include <bits/stdc++.h>
// #pragma GCC optimize "Ofast"
// #pragma GCC optimize "unroll-loops"
// #pragma GCC optimize "omit-frame-pointer"
// #pragma GCC optimize "prefetch-loop-arrays"
// #pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"


using namespace std;
const int MM = 1e9+7;
const int MAX = 1000010;
typedef long long ll;
vector<int> ob[1011];
int obSum[1011];
ll fac[MAX+10];
ll ans[1012];
ll mmi[MAX+10];
ll fmp(ll n,int p){
    if(p==1)return n;
    if(p==0)return 1;
    if(p%2==0)return fmp(((n%MM)*(n%MM)%MM),p/2)%MM;
    return fmp(((n%MM)*(n%MM)%MM),p/2)%MM*n%MM;
}
ll choose(int n,vector<int> k){
    long long ans=fac[n];
    for(int a:k){
        ans*=mmi[a];
        ans%=MM;
    }
    return ans;
}
ll sub(ll a,ll b){return (MM+a-b)%MM;}
bool f(vector<int> a,vector<int> b){
    int l = a.size()-1;
    for(int i=0; i<l; i++){
        if(a[i]!=b[i])return a[i]<b[i];
    }
}
int n;
bool in(int i,int j){
    for(int k=0; k<n; k++){
        if(ob[j][k]>ob[i][k])return false;
    }
    return true;
}
queue<int> buf;
int main() {
    fac[0]=1;
    mmi[0]=fmp(fac[0],MM-2);
    for(int i=1; i<=MAX; i++){
        fac[i]=(fac[i-1]*i)%MM;
        mmi[i]=fmp(fac[i],MM-2);
    }
    scanf("%d",&n);
    //Change n to q
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        buf.push(a);
    }
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++){
        for(int j=0,a; j<n; j++){
            scanf("%d",&a);
            ob[i].push_back(a-1);
            obSum[i]+=a-1;
        }
        ob[i].push_back(obSum[i]);
    }
    for(int i=0; i<n; i++){
        int a=buf.front();buf.pop();
        // printf("%d ",a);
        ob[q].push_back(a-1);
        obSum[q]+=a-1;
    }
    ob[q].push_back(obSum[q]);
    // printf("\n");
    sort(begin(ob),begin(ob)+q,f);
    for(int i=0; i<=q; i++){
        obSum[i]=ob[i][n];
        ob[i].pop_back();
    }
    for(int i=0; i<=q; i++){
        // printf("::%d ",obSum[i]);
        ans[i]=choose(obSum[i],ob[i]);
        // printf("%lld\n",ans[i]);
        // ans[i]=choose(ob[i].first+ob[i].second-2,ob[i].first-1);
        for(int j=0; j<i; j++){
            // if(in(i,j)){
            int moreRee=0;
            vector<int> ree;
            bool bad=false;
            for(int k=0; k<n; k++){
                // printf("%d %d\n",ob[i][k],ob[j][k]);
                if(ob[i][k]<ob[j][k]){
                    bad=true;
                    break;
                }
                moreRee+=ob[i][k]-ob[j][k];
                ree.push_back(ob[i][k]-ob[j][k]);
            }
            if(bad)break;
            // printf("%d\n",moreRee);
            ans[i]-=(ans[j]*choose(moreRee,ree))%MM;
            // printf("HI\n");
            // ans[i]-=(ans[j]*choose(
            //     ob[i].first-ob[j].first+ob[i].second-ob[j].second,
            //     ob[i].first-ob[j].first))%MM;
            if(ans[i]<0)ans[i]+=MM;
            // }
        }
    }
    printf("%lld\n",ans[q]);
    return 0;
}