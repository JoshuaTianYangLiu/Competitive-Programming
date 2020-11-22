#include <bits/stdc++.h>

using namespace std;
bool sieve[1000010];
vector<int> primes;
int f(int n){
    for(int i:primes){
        if(n%i==0)return i;
    }
    return n;
}
int main() {
    for(int i=2; i<1000010; i++){
        primes.push_back(i);
        if(!sieve[i]){
            for(int j=i; j<1000010; j+=i)sieve[j]=true;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        printf("%d\n",n+f(n)+2*k-2);
        // for(int i=0; i<k; i++){
        //     printf("::%d\n",f(n));
        //     n+=f(n);
        // }
        // printf("%d\n",n);
    }
    return 0;
}
