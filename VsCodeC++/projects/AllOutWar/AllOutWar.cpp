#include <bits/stdc++.h>

using namespace std;
int in[30030];
pair<long long,long long> tree[120120]; //val lazy
pair<long long,long long> comb(pair<long long,long long> l,pair<long long,long long> r){
    return {min(l.first,r.first),0};
}
void prop(int n){
    tree[2*n].second+=tree[n].second;tree[2*n+1].second+=tree[n].second;
    tree[2*n].first-=tree[2*n].second;
    tree[2*n+1].first-=tree[2*n+1].second;
    tree[2*n].second=0;
}
void build(int n,int l,int r){
    if(l==r)tree[n]={in[l],0};
    else{
        int m= (l+r)/2;
        build(2*n,l,m);build(2*n+1,m+1,r);
        tree[n]=comb(tree[2*n],tree[2*n+1]);
    }
}
void update(int n,int l,int r,int tl,int tr,int x){
    if(tl==l&&tr==r){
        tree[n].first-=x;
        tree[n].second+=x;
    }else{
        if(tree[n].second!=0)prop(n);
        int m = (l+r)/2;
        if(tr<=m)update(2*n,l,m,tl,tr,x);
        else if(tl>m)update(2*n+1,m+1,r,tl,tr,x);
        else update(2*n,l,m,tl,m,x),update(2*n+1,m+1,r,m+1,tr,x);
        tree[n]=comb(tree[2*n],tree[2*n+1]);
    }
}
long long query(int n,int l,int r,int tl,int tr){
    if(tl==l&&tr==r) return tree[n].first;
    if(tree[n].second!=0)prop(n);
    int m = (l+r)/2;
    if(tr<=m)return query(2*n,l,m,tl,tr);
    else if(tl>m)return query(2*n+1,m+1,r,tl,tr);
    else return min(query(2*n,l,m,tl,m),query(2*n+1,m+1,r,m+1,tr));
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    build(1,1,n);
    for(int i=0,a,b,c; i<q; i++){
        scanf("%d %d %d",&a,&b,&c);
        update(1,1,n,a,b,c);
        printf("%lld %lld\n",max(query(1,1,n,a,b),0ll),max(query(1,1,n,1,n),0ll));
    }

    return 0;
}