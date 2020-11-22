#include <bits/stdc++.h>

using namespace std;
struct point{
    int x,y;
    double d;
};
point in[21];
double memo[1<<21];
int n,l,r;
double PI = acos(-1);
double dist(double dist,point p){
    if(p.x-dist==0){
        double ret =p.y*tan(p.d);
        // printf("%.6lf %d %d %.6lf\n",dist,p.x,p.y,ret);
        return ret;
    }
    double a = atan(p.y/(p.x-dist));
    if(a<0)a=PI+a;
    double alpha = PI-a-p.d;
    if(alpha<0){
        printf("%d\n",r-l);
        exit(0);
    }
    double ll = sqrt((p.x-dist)*(p.x-dist)+p.y*p.y);
    double rr = ll*sin(a)/sin(alpha);
    // double dd = sqrt(ll*ll+rr*rr-2*ll*rr*cos(p.d));
    double dd;
    if(a>PI/2){
        dd=ll*sin(p.d)/sin(alpha);
    }else{
        dd = sqrt(ll*ll+rr*rr-2*ll*rr*cos(p.d));
    }
    // printf("%.6lf %d %d\n",dist,p.x,p.y);
    // printf("%.6lf %.6lf %.6lf %.6lf %.6lf\n",180*a/PI,180*alpha/PI,ll,rr,dd);
    return dd;
}
void f(int mask){
    if(memo[mask]!=l)return;
    if(mask==0)return;
    double ans=l;
    for(int i=0; i<n; i++){
        if((mask&(1<<i))!=0){
            int mmask=mask-(1<<i);
            // printf("::%d %d\n",mask,(mask&(1<<i)));
            f(mmask);
            ans=max(ans,memo[mmask]+dist(memo[mmask],in[i]));
            // printf("%d %.6lf %.6lf\n",mask,memo[mmask],ans);
        }
    }
    memo[mask]=max(memo[mask],ans);
}
int shift=0;
int main() {
    scanf("%d %d %d",&n,&l,&r);
    l+=shift;
    r+=shift;
    for(int i=0; i<(1<<21); i++)memo[i]=l;
    for(int i=0; i<n; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        a+=shift;
        b+=shift;
        in[i]={a,b,PI*c/180};
    }
    f((1<<n)-1);
    // printf("%.6lf\n",memo[(1<<n)-1]);
    printf("%.6lf\n",min(memo[(1<<n)-1]-l,(double)r-l));
    return 0;
}