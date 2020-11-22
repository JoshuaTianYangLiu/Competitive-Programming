#include <bits/stdc++.h>

using namespace std;

#define ln 2*n
#define rn 2*n+1

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
    void pushDown(int n){pd(n,tree,lazy);}
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

int up(int a,int b){
    // printf("::%d %d\n",a,b);
    return min(a?a:1e9,b?b:1e9);
}
void down(int n,vector<int> &tree,vector<pair<int,int>> &lazy){
    if(lazy[n].first==2){
        tree[ln]+=lazy[n].second;
        lazy[ln].first=2;
        lazy[ln].second+=lazy[n].second;
        tree[rn]+=lazy[n].second;
        lazy[rn].first=2;
        lazy[rn].second+=lazy[n].second;
    }else if(lazy[n].first==1){
        tree[ln]=lazy[n].second;
        lazy[ln]={1,lazy[n].second};
        tree[rn]=lazy[n].second;
        lazy[rn]={1,lazy[n].second};
    }
    lazy[n]={0,0};

}
void initt(int n,vector<int> &tree,vector<pair<int,int>> &lazy,pair<int,int> val){
    if(val.first==2){
        tree[n]+=val.second;
        lazy[n].first=2;
        lazy[n].second+=val.second;
    }else{
        tree[n]=val.second;
        lazy[n]={1,val.second};
    }
}
pair<int,int> ree[100010];
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    segtree<int,pair<int,int>> s(n,up,down,initt);
    for(int i=1; i<=n; i++){
        scanf("%d",&ree[i].second);
        ree[i].first=1;
    }
    s.build(ree);
    while(q--){
        int a,b,c,d;
        scanf("%d",&a);
        if(a==1){
            scanf("%d %d %d",&b,&c,&d);
            s.update(b,c,{2,d});
        }else if(a==2){
            scanf("%d %d %d",&b,&c,&d);
            s.update(b,c,{1,d});
        }else{
            scanf("%d %d",&b,&c);
            int e=s.query(b,c);
            assert(e>0);
            printf("%d\n",e);
        }
    }
    return 0;
}
