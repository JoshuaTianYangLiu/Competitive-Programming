#include <bits/stdc++.h>

using namespace std;
// typedef long long ll;
#define int long long
// Step 1 get r1=r2
// Step 2 get l1=l2
// Step 3 move r1 and r2 over
int calc(int l1,int r1,int l2,int r2,int k){
    if(k==0)return 0;
    // Assume l1<=l2
    // Step 1 and 2
    if(r2<=r1){
        //Encompass
        int t=min(r1,r2)-max(l1,l2);
        int u=max(r1,r2)-min(l1,l2);
        if(t>=k)return 0;
        if(k>u)return u-t+2*(k-u);
        return k-t;
    }else if(l2<=r1){
        //Overlap
        int t=min(r1,r2)-max(l1,l2);
        int u=max(r1,r2)-min(l1,l2);
        if(t>=k)return 0;
        if(k>u)return u-t+2*(k-u);
        return k-t;
    }else{
        int diff=l2-r1;
        int u=max(r1,r2)-min(l1,l2);
        if(k>u)return diff+u+2*(k-u);
        return k+diff;
        //No
    }
}
int calcc(int l1,int r1,int l2,int r2,int k){
    int e=calc(l1,r1,l2,r2,k);
    // printf("::%lld %lld\n",e,k);
    return e;
}
signed main() {
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,k,l1,r1,l2,r2;
        scanf("%lld %lld",&n,&k);
        scanf("%lld %lld",&l1,&r1);
        scanf("%lld %lld",&l2,&r2);
        if(l1>l2){
            swap(l1,l2);
            swap(r1,r2);
        }
        int u=max(r1,r2)-min(l1,l2);
        int tt=min(r1,r2)-max(l1,l2);
        if(k>u*n){
            // printf("u: %lld\n",u);
            int ans=calcc(l1,r1,l2,r2,u);
            ans*=n-1;
            ans+=calcc(l1,r1,l2,r2,k-u*(n-1));
            ans=min(ans,calcc(l1,r1,l2,r2,k));
            printf("%lld\n",ans);
        }else if(k<=tt*n){
            printf("0\n");
        }else{
            int t=k/u,v=k%u;
            int ans=calcc(l1,r1,l2,r2,u);
            ans*=t;
            ans+=calcc(l1,r1,l2,r2,v);
            ans=min(ans,calcc(l1,r1,l2,r2,k));
            printf("%lld\n",ans);

        }

    }
    return 0;
}