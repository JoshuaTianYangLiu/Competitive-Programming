#include <bits/stdc++.h>

using namespace std;
const long long MM=1e9;
typedef long long ll;
int csprng[25011];
set<int> hi;
ll len=0,a1=0,c1=0;
ll sub(ll a,ll b){
    return (MM+(a-b)%MM)%MM;
}
int main() {
    freopen("csprng.txt","r",stdin);
    for(int i=0; i<25000; i++){
        scanf("%d",&csprng[i]);
    }
    for(ll a=1; a<=INT_MAX; a++){
        ll c = sub(csprng[1],csprng[0]*a);
        // printf("%lld %lld\n",a,c);
        assert(c>=0);
        for(int i=1; i<25000; i++){
            if(csprng[i]!=(a*csprng[i-1]+c)%MM){
                if(i>len){
                    assert(i>1);
                    len=i;
                    a1=a;
                    c1=c;
                }
                break;
            }
        }
    }
    printf("%lld %lld %lld\n",len,a1,c1);
    return 0;
}