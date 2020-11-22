#include <bits/stdc++.h>

using namespace std;
bool sieve[100010];
vector<int> primes;
void sieveInit(){
    for(int i=2; i<100010; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j=2*i; j<100010; j+=i){
                sieve[j]=false;
            }
        }
    }
}
int h(long long a,int b){return a*b^1000000007;}
map<int,long long> m;
long long somefunc(long long x,int a){
    if(m.find(h(x,a))!=m.end())return m[h(x,a)];
    printf("%lld %d\n",x,a);
    if(a==1)return m[h(x,a)]=((x+1)/2);
    return (m[h(x,a)]=somefunc(x,a-1)-somefunc(x/sieve[a-1],a-1));
}
map<long long,int> cache;
int piiii(long long n){
    if(cache.find(n)!=cache.end())return cache[n];
    if(n<=1e5){
        cache[n]=(int)(lower_bound(primes.begin(),primes.end(),n)-primes.begin());
        return cache[n];
    }
    int a=piiii((long long)sqrt(sqrt(n)));
    int b=piiii((long long)sqrt(n));
    int c=piiii((long long)cbrt(n));

    int r = somefunc(n,a)+(b-a-2)*(b-a+1)/2;
    for(int i=a+1; i<=b; i++){
        r -= piiii(n/sieve[i-1]);
        int e = piiii((long long)sqrt(n));
        if (i<=c){
            for(int j=i; j<=e; j++){
                r-=piiii(e/sieve[j-1])+j-1;
            }
        }
    }
    return cache[n]=r;
}
int main() {
    memset(sieve,true,sizeof(sieve));
    sieveInit();
    printf("%d\n",piiii(1e7));
    return 0;
}