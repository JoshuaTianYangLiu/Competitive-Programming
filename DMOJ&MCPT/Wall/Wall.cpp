#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1

struct dataa {
    int mi=2e5,ma=0;
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
int pu(int a,int b){
    return max(a,b);
}
void pd(int n,vector<int> &tree,vector<dataa> &lazy){
    if(!(lazy[n].mi==2e5&&lazy[n].ma==0)){
        lazy[ln].mi=max(lazy[n].ma,min(lazy[ln].mi,lazy[n].mi));
        lazy[ln].ma=min(lazy[n].mi,max(lazy[ln].ma,lazy[n].ma));
        lazy[rn].mi=max(lazy[n].ma,min(lazy[rn].mi,lazy[n].mi));
        lazy[rn].ma=min(lazy[n].mi,max(lazy[rn].ma,lazy[n].ma));

        tree[ln]=min(lazy[ln].mi,lazy[ln].ma);
        tree[rn]=min(lazy[rn].mi,lazy[rn].ma);
        dataa a;
        lazy[n]=a;
    }
}
void init(int n,vector<int> &tree,vector<dataa> &lazy,dataa val){
    if(val.mi!=-1){
        lazy[n].mi=min(lazy[n].mi,val.mi);
        lazy[n].ma=min(lazy[n].ma,val.mi);
    }else{
        lazy[n].mi=max(lazy[n].mi,val.ma);
        lazy[n].ma=max(lazy[n].ma,val.ma);
    }
    // printf("::%d %d\n",lazy[n].mi,lazy[n].ma);
    tree[n]=min(lazy[n].mi,lazy[n].ma);
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    segtree<int,dataa> s(n,pu,pd,init,-1);
    for(int i=0,a,b,c,d; i<k; i++){
        a=op[i],b=left[i],c=right[i],d=height[i];
        if(a==1) s.update(b+1,c+1,{-1,d});
        if(a==2) s.update(b+1,c+1,{d,-1});
    }
    for(int i=1; i<=n; i++){
        finalHeight[i-1]=s.query(i);
    }
}
int main(){
    //Everytime i found the way to fix a bug another one is created, this is the lowest point in my programming career
    int n,k;
    scanf("%d %d",&n,&k);
    segtree<int,dataa> s(n,pu,pd,init,-1);
    for(int i=0,a,b,c,d; i<k; i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a==1) s.update(b+1,c+1,{-1,d});
        if(a==2) s.update(b+1,c+1,{d,-1});
    }
    for(int i=1; i<=n; i++){
        printf("%d ",s.query(i));
    }
    return 0;
}