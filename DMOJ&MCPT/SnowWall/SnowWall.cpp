#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1
struct snow{
    int pre,suf,l,r,len;
};
template <class T,class U>
class segtree {
    vector<T> tree;vector<U> lazy;
    T (*pu)(T,T);
    void (*pd)(int,vector<T>&,vector<U>&);
    void (*init)(int,int,int,vector<T>&,vector<U>&,U);
    T defVal;int N;
    public:
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&),void initialization(int,int,int,vector<T>&,vector<U>&,U),T def){
        defVal=def;pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+2));lazy.resize(4*(N+2));
    }
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&),void initialization(int,int,int,vector<T>&,vector<U>&,U)){
        if(typeid(T)==typeid(int))defVal=0;
        if(typeid(T)==typeid(long long))defVal=0;
        pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+1));lazy.resize(4*(N+1));
    }
    void pushUp(int n){tree[n]=pu(tree[ln],tree[rn]);}
    void pushDown(int n){if(lazy[n])pd(n,tree,lazy);}
    void build(int n,int l,int r,U in[]){
        if(l==r)init(n,l,r,tree,lazy,in[l]);
        else{
            int m=(l+r)/2;
            build(ln,l,m,in);build(rn,m+1,r,in);
            tree[n]=pu(tree[ln],tree[rn]);
        }
    }
    void update(int n,int l,int r,int tl,int tr,U val){
        if(tl>r||tr<l)return;
        if(tl<=l&&tr>=r){init(n,l,r,tree,lazy,val);return;}
        pushDown(n);int m=(l+r)/2;
        update(ln,l,m,tl,tr,val);
        update(rn,m+1,r,tl,tr,val);
        pushUp(n);
    }
    T query(int n,int l,int r,int tl,int tr){
        if(tl>r||tr<l)return defVal;
        if(tl<=l&&tr>=r)return tree[n];
        pushDown(n);int m=(l+r)/2;
        return pu(query(ln,l,m,tl,tr),query(rn,m+1,r,tl,tr));
    }
    void update(int tl,int tr,U val){update(1,1,N,tl,tr,val);}
    void update(int x,U val){update(x,x,val);}
    T query(int tl,int tr){return query(1,1,N,tl,tr);}
    T query(int x){return query(x,x);}
    void build(U in[]){build(1,1,N,in);}
};
snow pu(snow a,snow b){
    snow ret;
    ret.len=a.len+b.len;
    ret.l=ret.len+1;
    ret.r=ret.len+1;    
    if(a.len==a.pre)ret.pre=a.pre+b.pre;
    else ret.pre=a.pre;
    if(b.len==b.suf)ret.suf=b.suf+a.suf;
    else ret.suf=b.suf;
    int mm=max(a.suf+b.pre,max(ret.pre,max(ret.suf,max(a.r-a.l+1,b.r-b.l+1))));
    int aSufPos=a.len-a.suf+1;
    int retSufPos=ret.len-ret.suf+1;
    int bPos=a.len+b.l;
    int aPos=a.l;
    if(mm==ret.pre){
        ret.l=1,ret.r=ret.pre;
    }
    if(mm==a.suf+b.pre&&aSufPos<ret.l){
        ret.l=aSufPos;
        ret.r=a.len+b.pre;
    }
    if(mm==ret.suf&&retSufPos<ret.l){
        ret.l=retSufPos;
        ret.r=ret.len;
    }
    if(mm==a.r-a.l+1&&a.l<ret.l&&a.l!=0){
        ret.l=a.l;
        ret.r=a.r;
    }
    if(mm==b.r-b.l+1&&bPos<ret.l&&b.l!=0){
        ret.l=bPos;
        ret.r=b.r+a.len;
    }
    if(ret.l==ret.len+1){
        ret.l=ret.r=0;
    }
    // printf("MM: %d\n",mm);
    // printf("%d %d\n",aSufPos,a.len+b.pre);
    // printf("Snow a %d %d %d %d %d\nSnow b %d %d %d %d %d\nSnow ret %d %d %d %d %d\n\n",a.pre,a.suf,a.l,a.r,a.len,b.pre,b.suf,b.l,b.r,b.len,ret.pre,ret.suf,ret.l,ret.r,ret.len);
    return ret;
}
void pd(int n,vector<snow> &tree, vector<int> &lazy){
    // int m=(tree[n].len+1)/2;
    // tree[ln].len=m;
    // tree[rn].len=tree[n].len-m;
    if(lazy[n]==1){
        tree[ln]={0,0,0,0,tree[ln].len};
        tree[rn]={0,0,0,0,tree[rn].len};
    }else if(lazy[n]==2){
        tree[ln]={tree[ln].len,tree[ln].len,1,tree[ln].len,tree[ln].len};
        tree[rn]={tree[rn].len,tree[rn].len,1,tree[rn].len,tree[rn].len};
    }
    lazy[ln]=lazy[rn]=lazy[n];
    lazy[n]=0;
}
void init(int n,int l,int r,vector<snow> &tree, vector<int> &lazy,int val){
    if(val==1){
        tree[n]={0,0,0,0,r-l+1};
    }else if(val==2){
        tree[n]={r-l+1,r-l+1,1,r-l+1,r-l+1};
    }else if(val==3){
        tree[n]={0,0,0,0,r-l+1};
    }
    lazy[n]=val;
}
int ree[100010];
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n;i++)ree[i]=3;
    segtree<snow,int> s(n,pu,pd,init,{0,0,0,0,0});
    s.build(ree);
    while(q--){
        int a,b,c;
        scanf("%d",&a);
        if(a==0){
            scanf("%d %d",&b,&c);
            s.update(b,c,1);
            snow d=s.query(1,n);
            if(d.l!=0) printf("%d\n",d.r-d.l+1);
            else printf("0\n");
            // printf("::%d %d %d\n",d.r-d.l+1,d.l,d.r);
        }else if(a==1){
            scanf("%d %d",&b,&c);
            s.update(b,c,2);
            snow d=s.query(1,n);
            printf("%d\n",d.r-d.l+1);
            // printf("::%d %d %d\n",d.r-d.l+1,d.l,d.r);
        }else{
            snow d=s.query(1,n);
            
            s.update(d.l,d.r,1);
            d=s.query(1,n);
            // printf("::%d %d %d\n",d.r-d.l+1,d.l,d.r);
        }
    }
    return 0;
}