#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1

typedef long long ll;
typedef pair<ll,ll> pll;
char in[15];

template <class T,class U>
class segtree {
    vector<T> tree;vector<U> lazy;
    T (*pu)(T,T);
    void (*pd)(int,vector<T>&,vector<U>&,int,int);
    void (*init)(int,vector<T>&,vector<U>&,U,int,int);
    T defVal;int N;
    public:
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&,int,int),void initialization(int,vector<T>&,vector<U>&,U,int,int),T def){
        defVal=def;pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+1));lazy.resize(4*(N+1));
    }
    segtree(int n,T pushU(T,T),void pushD(int,vector<T>&,vector<U>&,int,int),void initialization(int,vector<T>&,vector<U>&,U,int,int)){
        if(typeid(T)==typeid(int))defVal=0;
        if(typeid(T)==typeid(long long))defVal=0;
        pu=pushU;pd=pushD;N=n;init=initialization;
        tree.resize(4*(N+1));lazy.resize(4*(N+1));
    }
    void pushUp(int n){tree[n]=pu(tree[ln],tree[rn]);}
    void pushDown(int n,int l,int r){pd(n,tree,lazy,l,r);}
    void build(int n,int l,int r,U in[]){
        if(l==r)init(n,tree,lazy,in[l],l,r);
        else{
            int m=(l+r)/2;
            build(ln,l,m,in);build(rn,m+1,r,in);
            tree[n]=pu(tree[ln],tree[rn]);
        }
    }
    void update(int n,int l,int r,int tl,int tr,U val){
        if(tl>r||tr<l)return;
        if(tl<=l&&tr>=r){init(n,tree,lazy,val,l,r);return;}
        pushDown(n,l,r);int m=(l+r)/2;
        update(ln,l,m,tl,tr,val);
        update(rn,m+1,r,tl,tr,val);
        pushUp(n);
    }
    T query(int n,int l,int r,int tl,int tr){
        if(tl>r||tr<l)return defVal;
        if(tl<=l&&tr>=r)return tree[n];
        pushDown(n,l,r);int m=(l+r)/2;
        return pu(query(ln,l,m,tl,tr),query(rn,m+1,r,tl,tr));
    }
    void update(int tl,int tr,U val){update(1,1,N,tl,tr,val);}
    void update(int x,U val){update(x,x,val);}
    T query(int tl,int tr){return query(1,1,N,tl,tr);}
    T query(int x){return query(x,x);}
    void build(U in[]){build(1,1,N,in);}
    ll queryamt(int n,ll q);
};
template <class T,class U>
ll segtree<T,U>::queryamt(int n,ll q){
    if(tree[n].first)
    //Ree cant decrement in a good way
}
// Num,Cost
pll up(pll a,pll b){
    return {a.first+b.first,a.second+b.second};
}
void down(int n,vector<pll> &tree, vector<pll> &lazy,int l,int r){
    if(lazy[n].second==0){
        lazy[n].first=0;
        lazy[ln]=lazy[rn]=lazy[n];
        tree[ln]={0,0};
        tree[rn]={0,0};
        lazy[n]={0,-1};
        return;
    }
    lazy[ln].first+=lazy[n].first;
    lazy[rn].first+=lazy[n].first;
    int m=(l+r)/2;
    tree[ln].first+=lazy[n].first;
    tree[ln].second+=lazy[n].first*(m-l+1)*(m+l)/2;
    tree[rn].first+=lazy[n].first;
    tree[rn].second+=lazy[n].first*(r-m)*(r+m+1)/2;
    lazy[n].first=0;
}
void init(int n,vector<pll> &tree, vector<pll> &lazy, pll val,int l,int r){
    lazy[n].first+=val.first;
    tree[n].first+=val.first;
    tree[n].second+=val.first*(r-l+1)*(l+r)/2;
}

int main() {
    int n;  
    ll num=0,cost=0;
    segtree<pll,pll> s(2000001,up,down,init,{0,0});
    scanf("%d",&n);
    while(n--){
        scanf("%s",in);
        if(!strncmp(in,"ADD",15)){
            int k,p;
            scanf("%d %d",&k,&p);
            num+=k;
            cost+=k*p;
            s.update(p,{k,0});
        }
        if(!strncmp(in,"ADDRANGE",15)){
            int a,b;
            scanf("%d %d",&a,&b);
            num+=b-a+1;
            cost+=(b-a+1)*(a+b)/2;
            s.update(a,b,{1,0});
        }
        if(!strncmp(in,"BUYAMT",15)){
            int q;
            scanf("%d",&q);
        }
        if(!strncmp(in,"BUYLOW",15)){
            int l;
            scanf("%d",&l);
        }
        if(!strncmp(in,"BUYHIGH",15)){
            int l;
            scanf("%d",&l);
        }
        if(!strncmp(in,"COST",15)){
            int l;
            scanf("%d",&l);
        }
        if(!strncmp(in,"NUMCONES",15)){
            printf("%d\n",num);
        }
        if(!strncmp(in,"TOTALCOST",15)){
            printf("%d\n",cost);
        }
    }
    return 0;
}