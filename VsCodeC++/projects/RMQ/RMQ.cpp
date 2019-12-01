#include <bits/stdc++.h>

using namespace std;
int in[100010];
int tree[400040];
void build(int p,int l, int r){
    if(l==r)tree[p]=in[l];
    else{
        int m=(l+r)/2;
        build(2*p,l,m);
        build(2*p+1,m+1,r);
        tree[p]=max(tree[2*p],tree[2*p+1]);
    }
}
int query(int p,int l,int r,int tl,int tr){
    if(tl>tr)return 0;
    if(l==tl&&r==tr)return tree[p];
    int m=(l+r)/2;
    return max(query(2*p,l,m,tl,min(tr,m)),query(2*p+1,m+1,r,max(tl,m+1),tr));

}
int main() {
    int n,m; 
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    build(1,1,n);
    for(int i=0,a,b; i<m; i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",query(1,1,n,a,b));
    }
    return 0;
}
