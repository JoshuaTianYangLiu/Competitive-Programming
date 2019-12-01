#include <bits/stdc++.h>

using namespace std;
int in[1000010];
int tree[4000040];
pair<int,int> treeG[4000040];
pair<int,int> comb(pair<int,int> a,pair<int,int> b){
    if(a.first==-1)return b;
    if(b.first==-1)return a;
    int c=__gcd(a.first,b.first);
    int t=0;
    if(a.first==c)t+=a.second;
    if(b.first==c)t+=b.second;
    return {c,t};
}
void build(int p,int l,int r){
    if(l==r)tree[p]=in[l],treeG[p]={in[l],1};
    else{
        int m=(l+r)/2;
        build(2*p,l,m);build(2*p+1,m+1,r);
        tree[p]=min(tree[2*p],tree[2*p+1]);
        treeG[p]=comb(treeG[2*p],treeG[2*p+1]);
    }
}
pair<int,int> query(int p,int l,int r,int tl,int tr,int type){
    if(tl>tr){
        if(type==1)return {2e9,0};
        else return {-1,0};
    }
    if(l==tl&&r==tr){
        if(type==1)return {tree[p],0};
        else return treeG[p];
    }
    int m=(l+r)/2;
    pair<int,int> ql=query(2*p,l,m,tl,min(tr,m),type);
    pair<int,int> qr=query(2*p+1,m+1,r,max(tl,m+1),tr,type);
    if(type==1){
        return {min(ql.first,qr.first),0};
    }else{
        return comb(ql,qr);
    }
}
void update(int p,int l,int r,int x,int v){
    if(l==r)tree[p]=v,treeG[p]={v,1};
    else{
        int m=(l+r)/2;
        if(x<=m) update(2*p,l,m,x,v);
        else update(2*p+1,m+1,r,x,v);
        tree[p]=min(tree[2*p],tree[2*p+1]);
        treeG[p]=comb(treeG[2*p],treeG[2*p+1]);
    }
}
int main() {
    //Im on a roll!
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++)
        scanf("%d",&in[i]);
    build(1,1,n);
    for(int i=0,b,c; i<q; i++){
        char a;
        scanf("%c",&a);
        while(a=='\n'||a==' ')scanf("%c",&a);
        scanf("%d %d",&b,&c);
        if(a=='C'){
            update(1,1,n,b,c);
        }else if(a=='M'){
            printf("%d\n",query(1,1,n,b,c,1).first);
        }else if(a=='G'){
            printf("%d\n",query(1,1,n,b,c,2).first);
        }else{
            printf("%d\n",query(1,1,n,b,c,2).second);
        }
    }
    return 0;
}
