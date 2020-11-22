#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
int brute(ll n){
    ll ret=1e18;
    int ree=0;
    for(int i=1; i<n; i++){
        ll a=i,b=n-i;
        if(a*b/__gcd(a,b)<ret){
            ret=a*b/__gcd(a,b);
            // printf("%lld %lld %d\n",a,b,ret);
            ree=a;
        }
    }
    return ree;
}
bool prime[100010];
vector<int> p;
int check(ll n){
    int ans=1e9;
    int ree=1;
    for(ll a:p){
        if(a*a>n){
            break;
        }
        if(n%a==0){
            if(lcm(n/a,n-n/a)<ans){
                ans=lcm(n/a,n-n/a);
                ree=n/a;
            }
        }
    }
    return ree;
}
int main() {
    for(int i=2; i<100010; i++){
        if(!prime[i]){
            p.push_back(i);
            for(int j=i; j<100010; j+=i)prime[j]=true;
        }
    }
    int i=2;
    while(true){
        printf("%d %d %d\n",i,check(i),brute(i));
        if(check(i)!=brute(i))break;
        i++;
    }
    // int t;
    // scanf("%d",&t);
    // while(t--){
    //     int n;
    //     scanf("%d",&n);
        
    //     // printf("%d %d\n",ree,n-ree);
    // }
    return 0;
}