#include <bits/stdc++.h>

using namespace std;

// The derivative of |a-x|^3 is -3|a-x|(a-x) but can be simplified down to |a-x|(x-a)
// The line seems to be searchable using bisection method
// Calculating the y value at any given point will need to use two bit (Maybe something more robust?)
// if x>a calculate (x-a)^2
// else calculate -(x-a)^2
// The sum of them can be represented as (# of num)*x^2-2*(a+b+c+...)x+(a^2+b^2+c^2+...)
// We can summarize each query using bit and something else if needed
// Is this right?
long long bitSq[30030],bit[30030],bitCnt[30030];
void updateSq(int x,int p){
    x+=15005;
    for(;x<30030; x+=x&-x)bitSq[x]+=p;
}
void update(int x,int p){
    x+=15005;
    for(;x<30030; x+=x&-x)bit[x]+=p;
}
void updateCnt(int x,int p){
    x+=15005;
    for(;x<30030; x+=x&-x)bitCnt[x]+=p;
}
long long querySq(int x){
    x+=15005;
    long long ret=0;
    for(;x;x-=x&-x)ret+=bitSq[x];
    return ret;
}
long long query(int x){
    x+=15005;
    long long ret=0;
    for(;x;x-=x&-x)ret+=bit[x];
    return ret;
}
long long queryCnt(int x){
    x+=15005;
    long long ret=0;
    for(;x;x-=x&-x)ret+=bitCnt[x];
    return ret;
}
long long querySq(int l,int r){
    return querySq(r)-querySq(l-1);
}
long long query(int l,int r){
    return query(r)-query(l-1);
}
long long queryCnt(int l,int r){
    return queryCnt(r)-queryCnt(l-1);
}
double calculate(double x1){
    long long lb=ceil(x1)-1;
    long long ub=floor(x1)+1;
    // printf("%lld %lld\n",lb,ub);
    long long leftA=queryCnt(lb);
    long long leftB=-2*query(lb);
    long long leftC=querySq(lb);
    long long rightA=-queryCnt(ub,15005);
    long long rightB=2*query(ub,15005);
    long long rightC=-querySq(ub,15005);
    // printf("%lld %lld %lld\n",rightA,rightB,rightC);
    leftA+=rightA,leftB+=rightB,leftC+=rightC;
    // printf("%lld %lld %lld\n",leftA,leftB,leftC);
    return leftA*x1*x1+leftB*x1+leftC;
}
int main() {
    int n;
    scanf("%d",&n);
    double l=30000,r=-30000;
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        updateSq(a,a*a);
        update(a,a);
        updateCnt(a,1);
        l=min(l,(double)a);
        r=max(r,(double)a);
        double m=(l+r)/2;
        double mm=calculate(m);
        double mmUb=1e9,mmLb=-1e9;
        while(abs(mm)>0.001){
            if(mm>0)r=m;
            else l=m;
            m=(l+r)/2;
            if(mm<0) mmLb=mm;
            else mmUb=mm;
            mm=calculate(m);
            // printf("%.6lf %.6lf %.6lf\n",mm,mmLb,mmUb);
            if(mm<0) assert(mmLb<mm);
            else assert(mm<mmUb);
            // printf("%.6lf\n",calculate(m));
        }
        printf("%.6lf\n",m);
    }
    return 0;
}