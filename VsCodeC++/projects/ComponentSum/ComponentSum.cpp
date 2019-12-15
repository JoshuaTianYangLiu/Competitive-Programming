#include <bits/stdc++.h>

using namespace std;
int cs[200020],bit[200020];
void update(int a,int b){
    for(;a<200020;a+=a&-a)bit[a]+=b;
}
int query(int a){
    int sum=0;
    for(;a;a-=a&-a)sum+=bit[a];
    return sum;
}
int ufds[200020],rnk[200020];
int fs(int n){return ufds[n]==n?n:fs(ufds[n]);}
bool ss(int a,int b){return fs(a)==fs(b);}
void us(int a,int b){
    if(!ss(a,b)){
        a=fs(a);
        b=fs(b);
        if(rnk[a]>rnk[b]){
            update(cs[a],-cs[a]);update(cs[b],-cs[b]);
            ufds[b]=a;
            cs[a]+=cs[b];
            cs[b]=0;
            update(cs[a],cs[a]);
        }else{
            update(cs[a],-cs[a]);update(cs[b],-cs[b]);
            ufds[a]=b;
            cs[b]+=cs[a];
            cs[a]=0;
            update(cs[b],cs[b]);
            if(rnk[a]==rnk[b])rnk[b]++;
        }
    }
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    update(1,n);
    for(int i=1; i<=n;i++){
        ufds[i]=i;cs[i]=1;
    }
    for(int i=0,a,b,c; i<q; i++){
        scanf("%d",&a);
        if(a==1){
            scanf("%d %d",&b,&c);
            us(b,c);
        }else{
            scanf("%d",&b);
            printf("%d\n",query(b));
        }
    }
    return 0;
}