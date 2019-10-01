#include <bits/stdc++.h>

using namespace std;
#define MM 1000000010
bitset<MM> bs;
vector<int> primes;
pair<int,int> pf[3000];
int main() {
    int n;
    scanf("%d",&n);
    bs.set();
    for(int i=2; i<=MM; i++){
        if(bs[i]){
            for(int j=i*i;j<=MM; j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
    int cnt=0,cnt1=0;
    while(n!=1){
        while(n%primes[cnt]==0){
            if(primes[cnt]!=pf[cnt1].first)cnt1++;
            pf[cnt1]={primes[cnt],pf[cnt1].second+1};
            n/=primes[cnt];
        }
        cnt++;
    }
    
    return 0;
}
