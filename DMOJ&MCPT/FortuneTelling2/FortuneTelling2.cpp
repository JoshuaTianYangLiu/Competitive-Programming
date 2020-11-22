#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1
// Assuming A<B
// Get index at which A<=T<B and count # of num which T>=B after
pair<int,int> pin[200020];
int kin[200020];
vector<int> coord;
map<int,int> rtoi;
int itor[600020];

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
    void build(int n,int l,int r,U In[]){
        if(l==r)init(n,tree,lazy,In[l]);
        else{
            int m=(l+r)/2;
            build(ln,l,m,In);build(rn,m+1,r,In);
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
    void build(U In[]){build(1,1,N,In);}
};

int up(int a,int b){
    return max(a,b);
}
void down(int n,vector<int> &tree,vector<int> &lazy){}
void init(int n,vector<int> &tree,vector<int> &lazy,int val){
    tree[n]=val;
}
bool f(pair<int,int> a,pair<int,int> b){
    return max(a.first,a.second)<max(b.first,b.second);
}
bool frev(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int bit[600040];
void update(int x,int p){
    assert(x>0);
    for(;x<600040; x+=x&-x)bit[x]+=p;
}
int query(int x){
    if(x<0)return 0;
    int ret=0;
    for(;x;x-=x&-x)ret+=bit[x];
    return ret;
}
int query(int l,int r){return query(r)-query(l-1);}
pair<int,int> kinn[200020];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        pin[i]={a,b};
        coord.push_back(a);
        coord.push_back(b);
    }
    for(int i=1; i<=k; i++){
        int a;
        scanf("%d",&a);
        kin[i]=a;
        coord.push_back(a);
    }
    sort(coord.begin(),coord.end());
    sort(pin+1,pin+1+n,f);
    int cnt=1;
    for(int a:coord){
        rtoi[a]=cnt;
        itor[cnt++]=a;
    }
    segtree<int,int> s(cnt,up,down,init);
    for(int i=1; i<=k; i++){
        s.update(rtoi[kin[i]],i);
        // buildCpy[rtoi[kin[i]]]=i;
        update(i,1);
        kinn[i]={kin[i],i};
    }
    sort(kinn+1,kinn+1+k,frev);
    // s.build(buildCpy);
    long long ans=0;
    int kpoint=1;
    for(int i=1; i<=n; i++){
        int mi=min(pin[i].first,pin[i].second);
        int ma=max(pin[i].first,pin[i].second);
        while(kpoint<=k&&kinn[kpoint].first<ma){
            update(kinn[kpoint].second,-1);
            kpoint++;
        }
        // printf("REE %d %d\n",rtoi[mi],rtoi[ma]-1);
        int idx=s.query(rtoi[mi],rtoi[ma]-1);
        // printf("%d %d\n",idx,cnt);
        int flips = query(idx,cnt);
        // printf("::%d %d\n",idx,flips);
        if(!idx){
            ans+=(flips%2)?pin[i].second:pin[i].first;
            // printf(":1: %d %d %d\n",mi,ma,(flips%2)?in[i].second:in[i].first);
        }else{
            ans+=(flips%2)?mi:ma;
            // printf(":0: %d %d %d\n",mi,ma,(flips%2)?mi:ma);
        }
    }
    printf("%lld\n",ans);

    return 0;
}