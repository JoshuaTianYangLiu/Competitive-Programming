#include <bits/stdc++.h>

using namespace std;
long long tree1[200003],tree2[200003];
int m,n,q;
void update(int type,int pos, long long val){
    if(type==1){
        for(;pos<200003;pos+=pos&-pos){
            tree1[pos]+=val;
        }
    }else{
        for(;pos<200003;pos+=pos&-pos){
            tree2[pos]+=val;
        }
    }
}
void rangeUpdate(int a,int b,long long val){
    update(1,a,val);
    update(1,b+1,-val);
    update(2,a,val*(a-1));
    update(2,b+1,-val*b);
}
long long query(int type,int pos){
    long long n=0;
    if(type==1)
        for(;pos;pos-=pos&-pos)n+=tree1[pos];
    else
        for(;pos;pos-=pos&-pos)n+=tree2[pos];
    return n;
}
long long query(int pos){return query(1,pos)*pos-query(2,pos);}
long long rangeQuery(int a,int b){return query(b)-query(a-1);}
int main() {
    scanf("%d %d %d",&m,&n,&q);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        rangeUpdate(i,i,a);
    }
    for(int i=1,a,b,c; i<=q; i++){
        scanf("%d",&a);
        if(a==1){
            long long d;
            scanf("%d %d %lld",&b,&c,&d);
            rangeUpdate(b,c,d);
        }else{
            scanf("%d %d",&b,&c);
            long long f=rangeQuery(b,c);
            f%=m;
            // if(f<0){
            //     long long e=f/m*-1;
            //     f=((1+e)*m+f)%m;
            // }
            printf("%lld\n",f);
        }
    }
    return 0;
}
