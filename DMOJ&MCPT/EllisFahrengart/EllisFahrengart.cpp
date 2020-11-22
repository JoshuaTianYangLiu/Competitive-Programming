#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
struct query{
    int l,r,idx;
};
query qu[100010];
const int s=400;
bool f(query a,query b){
    if(a.l/s==b.l/s){
        return (a.l/s&1)?(a.r<b.r):(a.r>b.r);
    }
    return a.l<b.l;
}

int in[100010];
ll aans[100010];
// int itor[100010];
gp_hash_table<int, int> rtoi;
int bit[100010];
void update(int x,int p){
    for(;x<100010; x+=x&-x)bit[x]+=p;
}
int queryy(int x){
    int ret=0;
    for(;x;x-=x&-x)ret+=bit[x];
    return ret;
}
int queryy(int l,int r){
    return queryy(r)-queryy(l-1);
}
int reee[100010];
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    // scanf("%d",&n);
    cin>>n;
    // s=ceil(sqrt(n))+200;
    // s=400;

    for(int i=0; i<n; i++){
        // scanf("%d",&in[i]);
        cin>>in[i];
        reee[i]=in[i];
        // ss.insert(in[i]);
    }
    sort(reee,reee+n);
    // sort(realCpy,realCpy+n);
    int cnt=1;
    for(int i=0; i<n; i++){
        rtoi[reee[i]]=cnt++;
    }
    // for(int i=0; i<n; i++){
    //     rtoi[realCpy[i]]=cnt++;
    // }
    // Map i to r
    int q;
    // scanf("%d",&q);
    cin>>q;
    for(int i=0; i<q; i++){
        // scanf("%d %d",&qu[i].l,&qu[i].r);
        cin>>qu[i].l>>qu[i].r;
        qu[i].l--;
        qu[i].r--;
        qu[i].idx=i;
    }
    sort(qu,qu+q,f);
    int l=0,r=-1;
    ll ans=0;
    ll cntt=0;
    for(int i=0; i<q; i++){
        while(l>qu[i].l){
            l--;
            int ree1=rtoi[in[l]];
            update(ree1,1);
            cntt++;
            ans+=queryy(ree1-1);
        }
        while(r<qu[i].r){
            r++;
            int ree1=rtoi[in[r]];
            update(ree1,1);
            cntt++;
            ans+=cntt-queryy(ree1);
        }
        while(l<qu[i].l){
            int ree1=rtoi[in[l]];
            update(ree1,-1);
            cntt--;
            ans-=queryy(ree1-1);
            l++;
        }
        while(r>qu[i].r){
            int ree1=rtoi[in[r]];
            update(ree1,-1);
            cntt--;
            ans-=cntt-queryy(ree1);
            r--;
        }
        aans[qu[i].idx]=ans;
    }
    for(int i=0; i<q; i++){
        // printf("%lld\n",aans[i]);
        cout<<aans[i]<<'\n';
    }
    return 0;
}