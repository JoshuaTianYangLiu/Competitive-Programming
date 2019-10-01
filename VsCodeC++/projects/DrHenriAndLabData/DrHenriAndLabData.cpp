#include <bits/stdc++.h>

using namespace std;
vector<long long> st(4000004);
pair<int,int> in[200002];
long long prefix[200002];
struct t{long long l;int r,k,pos;} q[200002];
bool f(t a,t b){return a.k<b.k;}
bool f1(t a,t b){return a.pos<b.pos;}
void update(int node,int idx,int val,int L,int R){
    if(L==R){
        st[node]+=val;
    }else{
        int M=(L+R)/2;
        if(L<=idx&&idx<=M){
            update(node*2,idx,val,L,M);
        }else{
            update(node*2+1,idx,val,M+1,R);
        }
        st[node]=st[2*node]+st[2*node+1];
    }
}
long long rsq(int node,int L,int R,int QL,int QR){
    if(L>QR||R<QL)return 0;
    if(QL<=L&&R<=QR)return st[node];
    int M=(L+R)/2;
    return rsq(2*node,L,M,QL,QR)+rsq(2*node+1,M+1,R,QL,QR);
}
int main() {
    int size,query;
    scanf("%d %d",&size,&query);
    for(int i=1,a; i<=size; i++){
        scanf("%d",&a);
        in[i]={a,i};
        prefix[i]+=prefix[i-1]+a;
    }
    sort(begin(in)+1,begin(in)+size+1);
    for(int i=1; i<=query; i++){
        scanf("%lld %d %d",&q[i].l,&q[i].r,&q[i].k); q[i].pos=i;
    }
    sort(begin(q)+1,begin(q)+query+1,f);
    int pos=1;

    for(int i=1; i<=query; i++){
        while(pos<=size&&in[pos].first<q[i].k){
            update(1,in[pos].second,in[pos].first,1,size);
            pos++;
        }
        q[i].l=prefix[q[i].r]-prefix[q[i].l-1]-2*rsq(1,1,size,q[i].l,q[i].r);
    }
    sort(begin(q)+1,begin(q)+query+1,f1);
    for(int i=1; i<=query; i++){
        printf("%lld\n",q[i].l);
    }
    return 0;
}
