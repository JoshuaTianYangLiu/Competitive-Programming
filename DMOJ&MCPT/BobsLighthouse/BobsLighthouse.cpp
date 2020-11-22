#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1
typedef pair<int,int> pi;

template <class T,class U>
class segtree {
    // T is tree data type and U is lazy data type
    vector<T> tree;vector<U> lazy;
    T (*pu)(T,T);
    void (*pd)(int,vector<T>&,vector<U>&);
    void (*init)(int,vector<T>&,vector<U>&,T);
    T defVal;int N;
    public:
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&),void initialization(int,vector<T>&,vector<U>&,T),T def){
        defVal=def;pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+1));lazy.resize(4*(N+1));
    }
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&),void initialization(int,vector<T>&,vector<U>&,T)){
        if(typeid(T)==typeid(int))defVal=0;
        if(typeid(T)==typeid(long long))defVal=0;
        pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+1));lazy.resize(4*(N+1));
    }
    void pushUp(int n){tree[n]=pu(tree[ln],tree[rn]);}
    // void pushDown(int n){if(lazy[n])pd(n,tree,lazy);}
    void pushDown(int n){pd(n,tree,lazy);}
    void build(int n,int l,int r,T In[]){
        if(l==r)init(n,tree,lazy,In[l]);
        else{
            int m=(l+r)/2;
            build(ln,l,m,In);build(rn,m+1,r,In);
            tree[n]=pu(tree[ln],tree[rn]);
        }
    }
    void update(int n,int l,int r,int tl,int tr,T val){
        if(tl>r||tr<l)return;
        if(tl<=l&&tr>=r){init(n,tree,lazy,val);return;}
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
    void update(int tl,int tr,T val){update(1,1,N,tl,tr,val);}
    void update(int x,T val){update(x,x,val);}
    T query(int tl,int tr){return query(1,1,N,tl,tr);}
    T query(int x){return query(x,x);}
    void build(T In[]){build(1,1,N,In);}
};

pi up(pi a,pi b){
    if(a.first>b.first)return a;
    return b;
}
void down(int n,vector<pi> &tree,vector<int> &lazy){
    if(lazy[n]){
        lazy[ln]+=lazy[n];
        lazy[rn]+=lazy[n];
        tree[ln].first+=lazy[ln];
        tree[rn].first+=lazy[rn];
        lazy[n]=0;
    }
}
void init(int n,vector<pi> &tree,vector<int> &lazy,pi val){
    if(val.second)tree[n]=val;
    else tree[n].first=val.first;
}
segtree<pi,int> s(100000,up,down,init,{0,0});
pi in[100010];
int n;
void setup(int pos,int diff){
    int cnt=0;
    for(int i=0; pos+(i-1)*(i-1)<=n||pos-(i-1)*(i-1)>=1; i++){
        s.update(min(pos+(i-1)*(i-1)+1,n+1),min(pos+i*i,n+1),{cnt,0});
        s.update(max(pos-i*i,0),max(pos-(i-1)*(i-1)-1,0),{cnt,0});
        cnt+=diff;
    }
}
int main() {
    
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i].first);
        in[i].second=i;
    }
    s.build(in);
    for(int i=1; i<=n; i++){
        setup(i,1);
        pair<int,int> a=s.query(1,n);
        printf("%d %d\n",a.first,a.second);
        setup(i,-1);
    }
    return 0;
}