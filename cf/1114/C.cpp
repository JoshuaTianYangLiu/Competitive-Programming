#include <bits/stdc++.h>

using namespace std;
// #define int unsigned long long;
bool sieve[1000010];
vector<unsigned long long> primes;
vector<unsigned long long> p;
vector<pair<unsigned long long,unsigned long long>> pf;
vector<unsigned long long> pp;
int main() {
    for(unsigned long long i=2; i<=1e6; i++){
        if(!sieve[i]){
            primes.push_back(i);
            for(unsigned long long j=i; j<=1e6; j+=i){
                sieve[j]=true;
            }
        }
    }
    long long n,b,bb;
    scanf("%lld %lld",&n,&b);
    bb=b;
    for(unsigned long long a:primes){
        if(bb%a==0)p.push_back(a);
        unsigned long long cnt=0;
        while(bb%a==0){
            bb/=a;
            cnt++;
        }
        if(cnt!=0)pf.push_back({a,cnt});
    }
    for(unsigned long long a:p){
        unsigned long long pow=0;
        unsigned long long nn=n; 
        for(unsigned long long i=a; i<=nn&&i>0; i*=a){
            pow+=nn/i;
            // nn/=i;
        }
        pp.push_back(pow);
    }
    // printf("Here");
    unsigned long long ans=1e18;
    for(unsigned long long i=0; i<p.size(); i++){
        unsigned long long a=pp[i];
        pair<unsigned long long,unsigned long long> b = pf[i];
        // printf("::%d %d %d\n",a,b.first,b.second);
        ans=min(ans,a/b.second);
    }
    printf("%lld\n",ans);
    return 0;
}