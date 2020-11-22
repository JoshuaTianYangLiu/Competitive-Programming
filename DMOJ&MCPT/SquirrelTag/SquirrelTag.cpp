#include <bits/stdc++.h>

using namespace std;
struct vec{
    double sx,sy,vx,vy;
};
vec in[16];
double findt(vec aa,int s,int x,int y){
    double r = sqrt(aa.vx*aa.vx+aa.vy*aa.vy);
    double theta = abs(atan2(aa.vy,aa.vx)-atan2(aa.sy-y,aa.sx-x));
    double len = sqrt((aa.sx-x)*(aa.sx-x)+(aa.sy-y)*(aa.sy-y));
    double a = s*s-r*r;
    double b = 2*len*r*cos(theta);
    double c = len*len;
    printf("%lf %lf %lf %lf %lf %lf\n",a,b,c,r,theta,len);
    return (-b+sqrt(b*b-4*a*c))/(2*a);
}
double solve(int caught,double time,double x,double y){

}
int main() {
    int n,s;
    scanf("%d %d",&n,&s);
    for(int i=1,a,b,c,d; i<=n; i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        in[i]={(double)a,(double)b,(double)c,(double)d};
    }
    
    printf("%.6lf\n",findt(in[1],s,0,0));
    return 0;
}