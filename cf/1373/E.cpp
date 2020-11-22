#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll f(ll x){
    ll ret=0;
    while(x){
        ret+=x%10;
        x/=10;
    }
    return ret;
}
ll solveNoCarry(int n,int k){
    int someConst = n-k*(k+1)/2;
    if(someConst>=0&&someConst%(k+1)==0){
        // printf("No carry const: %d\n",someConst/(k+1));
        int num=someConst/(k+1);
        // Reconstruct the number
        ll ret=min(num,9-k);
        num-=min(num,9-k);
        ll tens=10;
        while(num){
            ret+=min(9,num)*tens;
            num-=min(9,num);
            tens*=10;
        }
        // printf("Reconstructed %lld\n",ret);
        ll sum=0;
        for(int i=0; i<=k; i++){
            sum+=f(ret+i);
        }
        assert(sum==n);
        return ret;
    }
    return -1;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        printf("::%lld\n",solveNoCarry(n,k));
    }
    return 0;
}