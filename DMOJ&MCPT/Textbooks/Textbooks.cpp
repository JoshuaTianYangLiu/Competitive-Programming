#include <bits/stdc++.h>

using namespace std;
// Coordinate Compression and
// Seg tree with lazy propagation for 
// update: set l to r as v
// query get max of l to r
// Total area - Book area = Empty spaces
#include <bits/stdc++.h>

using namespace std;
#define ln 2*n
#define rn 2*n+1
typedef long long ll;
int tree[5000080],lazy[5000080];
void pushUp(int n){
    tree[n]=max(tree[ln],tree[rn]);
}
void pushDown(int n,int l,int r){
    if(lazy[n]){
        int m = (l+r)/2;
        tree[ln]=lazy[n],tree[rn]=lazy[n];
        lazy[ln]=lazy[n],lazy[rn]=lazy[n];
        lazy[n]=0;
    }
}
void update(int n,int l,int r,int tl,int tr,int val){
    if(tl>r||tr<l)return;
    if(tl<=l&&tr>=r){
        tree[n]=val,lazy[n]=val;
        return;
    }
    pushDown(n,l,r);
    int m=(l+r)/2;
    update(ln,l,m,tl,tr,val);
    update(rn,m+1,r,tl,tr,val);
    pushUp(n);
}
int query(int n,int l,int r,int tl,int tr){
    if(tl>r||tr<l)return 0;
    if(tl<=l&&tr>=r)return tree[n];
    pushDown(n,l,r);
    int m=(l+r)/2;
    return max(query(ln,l,m,tl,tr),query(rn,m+1,r,tl,tr));
}
map<int,int> rtoi;
int itor[2000010];
struct triple{
    int first,second,third;
};
bool f(triple a,triple b){}
queue<triple> q;
set<int> in;
const int MM=1e9+7;
int main() {
    ll ans=0;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int s,l,w;
        scanf("%d %d %d",&s,&l,&w);
        ans-=(ll)l*w;
        ans%=MM;
        q.push({s,l,w});
        in.insert(s);
        in.insert(s+l-1);
        if(s>1)in.insert(s-1);
        in.insert(s+l);
    }
    int imaginary=1;
    for(int a:in){
        itor[imaginary]=a;
        rtoi[a]=imaginary++;
    }
    assert(imaginary<=2000000);
    while(q.size()){
        triple f = q.front();q.pop();
        int l=rtoi[f.first],r=rtoi[f.first+f.second-1];
        ll height=query(1,0,imaginary,l,r)+f.third;
        // printf("Compressed Coords: %d %d\n Height: %lld\n Real Values %d %d %d\n",l,r,height,f.first,f.first+f.second-1,f.third);
        update(1,0,imaginary,l,r,height);
    }
    for(int i=1; i<imaginary-1; i++){
        ll a=query(1,0,imaginary,i,i);
        int l=itor[i],r=itor[i+1];
        // printf("::%d %d %lld\n",l,r-1,a);
        ans+=a*(r-l);
        ans%=MM;
    }
    printf("%lld\n",ans);

    return 0;
}