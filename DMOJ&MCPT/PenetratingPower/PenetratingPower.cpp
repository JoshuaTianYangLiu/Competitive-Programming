#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1
typedef long long ll;
ll tree[800080],lazy[800080];
void pushUp(int n){
    tree[n]=max(tree[ln],tree[rn]);
}
void pushDown(int n,int l,int r){
    if(lazy[n]){
        int m = (l+r)/2;
        tree[ln]+=lazy[n],tree[rn]+=lazy[n];
        lazy[ln]+=lazy[n],lazy[rn]+=lazy[n];
        lazy[n]=0;
    }
}
void update(int n,int l,int r,int tl,int tr,int val){
    if(tl>r||tr<l)return;
    if(tl<=l&&tr>=r){
        tree[n]+=val,lazy[n]+=val;
        return;
    }
    pushDown(n,l,r);
    int m=(l+r)/2;
    update(ln,l,m,tl,tr,val);
    update(rn,m+1,r,tl,tr,val);
    pushUp(n);
}
ll query(int n,int l,int r,int tl,int tr){
    if(tl>r||tr<l)return 0;
    if(tl<=l&&tr>=r)return tree[n];
    pushDown(n,l,r);
    int m=(l+r)/2;
    return max(query(ln,l,m,tl,tr),query(rn,m+1,r,tl,tr));
}
int main() {
    int n,k,q,a,b,c;
    scanf("%d %d %d",&n,&k,&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        if(a==0){
            update(1,0,n,max(b-k+1,0),b,c);
        }else{
            printf("%lld\n",query(1,0,n,b,c));
        }
    }
    return 0;
}