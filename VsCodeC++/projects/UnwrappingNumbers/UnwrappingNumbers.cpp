#include <bits/stdc++.h>

using namespace std;
#define ll long long
int s(ll n){
    int s=0;
    while(n)s+=n%10,n/=10;
    return s;
}
int main() {
    ll a;
    scanf("%lld",&a);
    queue<pair<ll,int>> q;
    q.push({a,0});
    while(!q.empty()){
        pair<ll,int> u = q.front(); q.pop();
        if(u.first==1){
            printf("%d\n",u.second);
            return 0;
        }
        q.push({u.first-1,u.second+1});
        q.push({u.first/s(u.first),u.second+1});
    }
    return 0;
}