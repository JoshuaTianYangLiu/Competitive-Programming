#include <bits/stdc++.h>

using namespace std;
int tree[100003];
pair<int,int> in[100003];
int prefix[100003];
struct query{int l,r,q,pos;} qu[100003];
bool f(query a,query b){return a.q<b.q;}
bool f2(query a,query b){return a.pos<b.pos;}
void update(int x,int val){
    for(;x<100003;x+=x&-x)tree[x]+=val;
}
int rsq(int x){
    int n=0;
    for(;x;x-=x&-x)n+=tree[x];
    return n;
}
int rsq(int x,int y){return rsq(y)-rsq(x);}
int main() {
    int size,q;
    scanf("%d",&size);
    for(int i=1,a; i<=size; i++){
        scanf("%d",&a);
        in[i]={a,i};
        prefix[i]=prefix[i-1]+a;
    }
    sort(begin(in)+1,begin(in)+1+size);
    scanf("%d",&q);
    for(int i=1; i<=q; i++){
        scanf("%d %d %d",&qu[i].l,&qu[i].r,&qu[i].q);qu[i].pos=i;
        qu[i].l++;qu[i].r++;
    }
    sort(begin(qu)+1,begin(qu)+1+q,f);
    int pos=1;
    for(int i=1; i<=q; i++){
        while(pos<=size&&in[pos].first<qu[i].q){
            update(in[pos].second,in[pos].first);
            pos++;
        }
        qu[i].l=prefix[qu[i].r]-prefix[qu[i].l-1]-rsq(qu[i].l-1,qu[i].r);
    }
    sort(begin(qu)+1,begin(qu)+1+q,f2);
    for(int i=1; i<=q; i++){
        printf("%d\n",qu[i].l);
    }
    return 0;
}
