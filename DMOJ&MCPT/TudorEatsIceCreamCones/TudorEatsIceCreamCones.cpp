#include <bits/stdc++.h>

using namespace std;
int in[1000010];
pair<int,int> emp1={0,0},emp2={2e9,2e9};
pair<int,int> tree1[4000040],tree2[4000040];
pair<int,int> twoMax(pair<int,int> a,pair<int,int> b){
    int ret1,ret2;
    if(a.first>a.second&&a.first>b.first&&a.first>b.second)ret1=a.first,a.first=0;
    else if(a.second>b.first&&a.second>b.second)ret1=a.second,a.second=0;
    else if(b.first>b.second)ret1=b.first,b.first=0;
    else ret1=b.second,b.second=0;
    if(a.first>a.second&&a.first>b.first&&a.first>b.second)ret2=a.first;
    else if(a.second>b.first&&a.second>b.second)ret2=a.second;
    else if(b.first>b.second)ret2=b.first;
    else ret2=b.second;
    return {ret1,ret2};
}
pair<int,int> twoMin(pair<int,int> a,pair<int,int> b){
    int ret1,ret2;
    if(a.first<a.second&&a.first<b.first&&a.first<b.second)ret1=a.first,a.first=2e9;
    else if(a.second<b.first&&a.second<b.second)ret1=a.second,a.second=2e9;
    else if(b.first<b.second)ret1=b.first,b.first=2e9;
    else ret1=b.second,b.second=2e9;
    if(a.first<a.second&&a.first<b.first&&a.first<b.second)ret2=a.first;
    else if(a.second<b.first&&a.second<b.second)ret2=a.second;
    else if(b.first<b.second)ret2=b.first;
    else ret2=b.second;
    return {ret1,ret2};
}
void build(int p,int l,int r){
    if(l==r){
        tree1[p]={in[l],2e9};
        tree2[p]={in[l],-1};
    }else{
        int m=(l+r)/2;
        build(2*p,l,m); build(2*p+1,m+1,r);
        tree1[p]=twoMin(tree1[2*p],tree1[2*p+1]);
        tree2[p]=twoMax(tree2[2*p],tree2[2*p+1]);
    }
}
pair<int,int> query(int p,int l,int r,int tl,int tr,int type){
    
    if(tl>tr)
        if(type==1)
            return{2e9,2e9};
        else
            return{0,0};
    if(l==tl&&r==tr)
        if(type==1)
            return tree1[p];
        else
            return tree2[p];
    else{
        int m=(l+r)/2;
        pair<int,int> ql=query(2*p,l,m,tl,min(tr,m),type);
        pair<int,int> qr=query(2*p+1,m+1,r,max(tl,m+1),tr,type);
        //printf("\t%d %d %d %d\n",ql.first,ql.second,qr.first,qr.second);
        //printf("\t%d %d %d\n",l,m,r);
        if(ql==emp1||ql==emp2)return qr;
        if(qr==emp1||qr==emp2)return ql;
        if(type==1) return twoMin(ql,qr);
        else return twoMax(ql,qr);
    }
}
void update(int p,int l,int r,int x,int v){
    if(l==r){
        tree1[p]={v,2e9};
        tree2[p]={v,-1};
    }else{
        int m=(l+r)/2;
        if(x<=m)update(2*p,l,m,x,v);
        else update(2*p+1,m+1,r,x,v);
        tree1[p]=twoMin(tree1[2*p],tree1[2*p+1]);
        tree2[p]=twoMax(tree2[2*p],tree2[2*p+1]);
    }
}
int main() {
    //Oh god this code
    //Somehow it's correct
    int n,q;
    scanf("%d %d",&n,&q);
    int sqrtn=(int)round(sqrt(n));
    for(int i=1; i<=n; i++){
        scanf("%d ",&in[i]);
        //printf("\t%d\n",in[i]);
    }
    build(1,1,n);
    int ans=0;
    for(int i=0,a,b,c; i<q; i++){
        scanf("%d %d %d",&a,&b,&c);
        b^=ans;
        c^=ans;
        //printf("\t%d %d %d %.3lf\n",a,b,c,sqrtn);
        if(a==1){
            update(1,1,n,b,c);
        }else if(a==2){
            b--;
            b=max((int)floor(b*sqrtn)+1,1);
            c=min((int)floor(c*sqrtn),n);
            //printf("\t\t%d %d\n",b,c);
            pair<int,int> t=query(1,1,n,b,c,1);
            ans=t.first+t.second;
            printf("%d\n",ans);
        }else{
            b--;
            b=max((int)floor(b*sqrtn)+1,1);
            c=min((int)floor(c*sqrtn),n);
            //printf("\t\t%d %d\n",b,c);
            pair<int,int> t=query(1,1,n,b,c,2);
            ans=t.first+t.second;
            printf("%d\n",ans);
        }
    }
    return 0;
}
