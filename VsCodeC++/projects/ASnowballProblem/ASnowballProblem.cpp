#include <bits/stdc++.h>

using namespace std;

int main() {
    double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    //M R H theta
    double ans = 2*c*sin(d)/sqrt(4*9.81*c/3);
    printf("%.7lf",ans);
    return 0;
}