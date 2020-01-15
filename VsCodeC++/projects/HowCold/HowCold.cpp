#include <bits/stdc++.h>

using namespace std;
double c(int a){
    return (5*(a-32))/9.0;
}
int main() {
    double b[6];
    scanf("%lf %lf %lf %lf %lf %lf",&b[0],&b[1],&b[2],&b[3],&b[4],&b[5]);
    for(int i=0; i<64; i++){
        double a[6];
        for(int j=0; j<6; j++){
            if((i&(1<<j))!=0){
                a[j]=c(b[j]);
            }else{
                a[j]=b[j];
            }
        }
        if(a[0]<a[1]&&a[1]<a[2]&&a[2]<a[3]&&a[3]<a[4]&&a[4]<a[5]){
            printf("%.2f %.2f %.2f %.2f %.2f %.2f\n",a[0],a[1],a[2],a[3],a[4],a[5]);
            // return 0;
        }
    }
    printf("Impossible");
    return 0;
}