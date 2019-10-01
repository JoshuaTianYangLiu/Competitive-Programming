#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x,y,z;
    int n;
    unordered_map<pair<long long,pair<long long,long long>>,int> um;
    scanf("%lld %lld %lld %d",&x,&y,&z,&n);
    for(int i=0; i<n; i++){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        um.insert({a,{b,c}});
    }
    return 0;
}
