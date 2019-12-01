#include <bits/stdc++.h>

using namespace std;
int in[100010];
struct sum{long long sum,ls,rs,ans;};
sum tree[4000040];
sum combine(sum a,sum b){
    sum ret;
    ret.sum=a.sum+b.sum;
    ret.ls=max(a.ls,a.sum+b.ls);
    ret.rs=max(b.rs,a.rs+b.sum);
    ret.ans=max(max(a.ans,b.ans),a.rs+b.ls);
    return ret;
}
sum mkData(int p){
    sum ret;
    ret.sum=p;
    ret.ls=ret.rs=ret.ans=max(p,INT_MIN);
    return ret;
}
void build(int p,int l,int r){
    if(l==r)tree[p]=mkData(in[l]);
    else{
        int m=(l+r)/2;
        build(2*p,l,m); build(2*p+1,m+1,r);
        tree[p]=combine(tree[2*p],tree[2*p+1]);
    }
}
sum query(int p,int l,int r,int tl,int tr){
    if(tl>tr)return mkData(INT_MIN);
    if(l==tl&&r==tr) return tree[p];
    int m=(l+r)/2;
    return combine(query(2*p,l,m,tl,min(tr,m)),query(2*p+1,m+1,r,max(tl,m+1),tr));
}
void update(int p,int l,int r,int x,int v){
    if(l==r)tree[p]=mkData(v);
    else{
        int m=(l+r)/2;
        if(x<=m)update(2*p,l,m,x,v);
        else update(2*p+1,m+1,r,x,v);
        tree[p]=combine(tree[2*p],tree[2*p+1]);
    }
}
int main() {    //Similar to holy grail war just copied the code
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    build(1,1,n);
    for(int i=0; i<q; i++){
        char a;
        scanf("%c",&a);
        while(a==' '||a=='\n')scanf("%c",&a);
        int b,c;
        scanf("%d %d",&b,&c);
        if(a=='S')update(1,1,n,b,c);
        else printf("%lld\n",query(1,1,n,b,c).ans);
    }
    return 0;
}
