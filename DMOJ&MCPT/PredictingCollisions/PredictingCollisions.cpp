#include <bits/stdc++.h>

using namespace std;
int func[6];
double calcFun(double n){
    double ret=0;
    for(int i=0; i<6; i++){
        ret+=func[i]*pow(n,i);
    }
    return ret;
}
int main() {
    int n,m;
    scanf("%d",&n);
    for(int i=n; i>=0; i--){
        scanf("%d",&func[i]);
    }
    scanf("%d",&m);
    for(int i=m,a; i>=0; i--){
        scanf("%d",&a);
        func[i]-=a;
    }
    double a,b;
    scanf("%lf %lf",&a,&b);
    double c=(a+b)/2;
    while (b-a>0.000000001){
        c = (a+b)/2;
        if(calcFun(c)*calcFun(a)>0){
            a=c;
        }else{
            b=c;
        }
    }
    printf("%.8f",c);
    return 0;
}