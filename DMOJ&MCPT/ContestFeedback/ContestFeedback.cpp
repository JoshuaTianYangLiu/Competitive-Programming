#include <bits/stdc++.h>

using namespace std;
double e(int a,int b){
    return (a+b)/2.0;
}
double f(int a,int b,int c){
    return (a+b+c)/3.0;
}
double g(int a,int b,int c, int d){
    return (a+b+c+d)/4.0;
}
int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%lf\n",e(a,b));
    printf("%lf\n",e(a,c));
    printf("%lf\n",e(a,d));
    printf("%lf\n",e(b,c));
    printf("%lf\n",e(b,d));
    printf("%lf\n",e(c,d));
    printf("%lf\n",f(a,b,c));
    printf("%lf\n",f(a,b,d));
    printf("%lf\n",f(a,c,d));
    printf("%lf\n",f(b,c,d));
    printf("%lf\n",g(a,b,c,d));
    return 0;
}
