#include <bits/stdc++.h>

using namespace std;
long long arr[100010];
long long psa[100010];
int n,a,r,m;
long long solve(int i){
    int idx = lower_bound(begin(arr)+1,begin(arr)+1+n,i)-begin(arr)-1;
    long long opA = (i)*(idx)-psa[idx];
    long long opR = psa[n]-psa[idx]-i*(n-idx);
    // printf("::%lld %lld %d %d\n",opA,opR,idx,i);
    long long out=0;
    long long ans=0;
    if(m<a+r){
        out=min(opA,opR);
        ans+=m*out;
        opA-=out;
        opR-=out;
        ans+=a*opA+r*opR;
    }else{
        ans+=a*opA+r*opR;
    }
    return ans;
}
int main() {
    scanf("%d %d %d %d",&n,&a,&r,&m);
    if(a==0||r==0){
        printf("0\n");
        return 0;
    }
    int mi=0,ma=0;
    for(int i=1,a; i<=n;i++){
        scanf("%d",&a);
        mi=min(mi,a);
        ma=max(ma,a);
        arr[i]=a;
    }
    sort(begin(arr)+1,begin(arr)+1+n);
    for(int i=1; i<=n; i++){
        psa[i]=arr[i]+psa[i-1];
    }
    long long finalAns=1e9;
    // long long aami=solve(mi),aama=solve(ma);
    int m;
    long long aa;
    while(mi<=ma){
        m = (mi+ma)/2;
        aa=solve(m);
        long long left = solve(m-1);
        long long right = solve(m+1);
        if(left>=aa&&right<=aa)mi=m+1;
        else if(left<=aa&&right>=aa)ma=m-1;
        else{
            printf("%lld\n",aa);
            return 0;
        }
    }
    printf("%lld\n",aa);
    
    return 0;
}