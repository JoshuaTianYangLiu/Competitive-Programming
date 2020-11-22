#include <bits/stdc++.h>

using namespace std;
long long tree[200002];
pair<int,int> in[200002];
long long prefix[200002];
struct t{long long l;int r,k,pos;} q[200002];
bool f(t a,t b){return a.k<b.k;}
bool f1(t a,t b){return a.pos<b.pos;}
void update(int pos,int val){
    for(;pos<200002;pos+=pos&-pos)tree[pos]+=val;
}
long long rsq(int pos){
    long long n=0;
    for(;pos;pos-=pos&-pos)n+=tree[pos];
    return n;
}
long long rsq(int x,int y){return rsq(y)-rsq(x);}
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
            update(in[pos].second,in[pos].first);
            pos++;
        }
        q[i].l=prefix[q[i].r]-prefix[q[i].l-1]-2*rsq(q[i].l-1,q[i].r);
    }
    sort(begin(q)+1,begin(q)+query+1,f1);
    for(int i=1; i<=query; i++){
        printf("%lld\n",q[i].l);
    }
    return 0;
}
