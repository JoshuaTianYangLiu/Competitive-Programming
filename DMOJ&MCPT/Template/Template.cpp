#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1

struct triple{
    int first,second,third;
};

class ufds {
    vector<int> uf,rnk;int N;
    public:
    ufds(int n){uf.resize(n+1);rnk.resize(n+1);N=n;init();}
    int operator[](int idx){return uf[idx];}
    void init(int n){N=n;init();}
    void init(){rnk.resize(N+1,0);for(int i=0; i<=N; i++)uf[i]=i;}
    int findSet(int i){return uf[i]==i?i:(uf[i]=findSet(uf[i]));}
    bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
    void unionSet(int i,int j){if(!isSameSet(i,j)){
        int u = findSet(i),v = findSet(j);
        if(rnk[u]>rnk[v])uf[v]=u;
        else{uf[u]=v;if(rnk[u]==rnk[v])rnk[v]++;}}}
};

template <class T,class U>
class segtree {
    vector<T> tree;vector<U> lazy;
    T (*pu)(T,T);
    void (*pd)(int,vector<T>&,vector<U>&);
    void (*init)(int,vector<T>&,vector<U>&,U);
    T defVal;int N;
    public:
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&),void initialization(int,vector<T>&,vector<U>&,U),T def){
        defVal=def;pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+1));lazy.resize(4*(N+1));
    }
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&),void initialization(int,vector<T>&,vector<U>&,U)){
        if(typeid(T)==typeid(int))defVal=0;
        if(typeid(T)==typeid(long long))defVal=0;
        pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+1));lazy.resize(4*(N+1));
    }
    void pushUp(int n){tree[n]=pu(tree[ln],tree[rn]);}
    void pushDown(int n){if(lazy[n])pd(n,tree,lazy);}
    // void pushDown(int n){pd(n,tree,lazy);}
    void build(int n,int l,int r,U in[]){
        if(l==r)init(n,tree,lazy,in[l]);
        else{
            int m=(l+r)/2;
            build(ln,l,m,in);build(rn,m+1,r,in);
            tree[n]=pu(tree[ln],tree[rn]);
        }
    }
    void update(int n,int l,int r,int tl,int tr,U val){
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
    void update(int tl,int tr,U val){update(1,1,N,tl,tr,val);}
    void update(int x,U val){update(x,x,val);}
    T query(int tl,int tr){return query(1,1,N,tl,tr);}
    T query(int x){return query(x,x);}
    void build(U in[]){build(1,1,N,in);}
};

triple up(triple a,triple b){
    triple ret;
    ret.first=min(a.first,b.first);
    if(a.second==-1)return {ret.first,b.second,b.third};
    if(b.second==-1)return {ret.first,a.second,a.third};
    ret.second=__gcd(a.second,b.second);
    ret.third=0;
    if(a.second==ret.second)ret.third+=a.third;
    if(b.second==ret.second)ret.third+=b.third;
    return ret;
}
void down(int n,vector<triple> &tree,vector<int> &lazy){

}
void initt(int n,vector<triple> &tree,vector<int> &lazy,int val){
    tree[n]={val,val,1};
}
int in[100010];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    segtree<triple,int> s(n,up,down,initt,{(int)2e9,-1,0});
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    s.build(in);
    for(int i=0,b,c; i<m; i++){
        char a;
        scanf("%c",&a);
        while(a=='\n'||a==' ')scanf("%c",&a);
        scanf("%d %d",&b,&c);
        if(a=='C'){
            s.update(b,c);
        }else if(a=='M'){
            printf("%d\n",s.query(b,c).first);
        }else if(a=='G'){
            printf("%d\n",s.query(b,c).second);
        }else{
            printf("%d\n",s.query(b,c).third);
        }
    }
    return 0;
}