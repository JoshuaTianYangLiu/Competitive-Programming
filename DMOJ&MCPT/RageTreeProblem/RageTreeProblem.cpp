#include <bits/stdc++.h>

using namespace std;
int treeMin[200010];
int treeMax[200010];
int in[50010];
pair<int,int> emp={0,0};
void build(int p,int l,int r){
    if(l==r)treeMin[p]=in[l],treeMax[p]=in[l];
    else{
        int m=(l+r)/2;
        build(2*p,l,m);
        build(2*p+1,m+1,r);
        treeMin[p]=min(treeMin[2*p],treeMin[2*p+1]);
        treeMax[p]=max(treeMax[2*p],treeMax[2*p+1]);
    }
}
pair<int,int> query(int p,int l,int r,int tl,int tr){
    //printf("%d %d %d %d %d\n",p,l,r,tl,tr);
    if(tl>tr)return {0,0};
    if(l==tl&&r==tr)return {treeMax[p],treeMin[p]};
    else{
        int m=(l+r)/2;
        pair<int,int> ql=query(2*p,l,m,tl,min(tr,m));
        pair<int,int> qr=query(2*p+1,m+1,r,max(tl,m+1),tr);
        if(ql==emp)return qr;
        if(qr==emp)return ql;
        return {max(ql.first,qr.first),min(ql.second,qr.second)};
    }
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++)
        scanf("%d",&in[i]);
    build(1,1,n);
    for(int i=0,a,b; i<q; i++){
        scanf("%d %d",&a,&b);
        pair<int,int> t=query(1,1,n,a,b);
        printf("%d\n",t.first-t.second);
    }
    return 0;
}
