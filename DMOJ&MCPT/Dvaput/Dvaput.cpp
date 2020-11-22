#include <bits/stdc++.h>

using namespace std;
char in[200020];
long long ppow[200020];
long long hhash[200020];
int n;
int MM=1e9+7,BB=1637;
bool canMatch(int k){
    if(k==0)return true;
    set<long long> ss;
    for(int i=0; i<=n-k; i++){
        long long q = (hhash[i+k]-hhash[i]+MM)%MM;
        q=(q*ppow[n-i-1])%MM;
        printf("%d %d %lld %d\n",i,i+k-1,q,k);
        if(ss.count(q))return true;
        ss.insert(q);
    }
    return false;
}
int main() {
    scanf("%d",&n);
    scanf("%s",in);
    ppow[0]=1;
    for(int i=1;i<=n; i++){
        ppow[i]=(BB*ppow[i-1])%MM;
    }
    for(int i=0; i<n; i++){
        hhash[i+1]=(hhash[i]+(in[i]-'a'+1)*ppow[i])%MM;
    }
    int l=0,r=n,m;
    while(l<=r){
        m=(l+r)/2;
        if(canMatch(m))l=m+1;
        else r=m-1;
    }
    printf("%d\n",r);
    return 0;
}