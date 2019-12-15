#include <bits/stdc++.h>

using namespace std;
double c(int a){
    return 1.8*a+32;
}
int main() {
    double b[3];
    scanf("%lf %lf %lf",&b[0],&b[1],&b[2]);
    for(int i=0; i<8; i++){
        double a[3];
        for(int j=0; j<3; j++){
            if((i&(1<<j))!=0){
                a[j]=c(b[j]);
            }else{
                a[j]=b[j];
            }
        }
        if(a[0]<a[1]&&a[1]<a[2]){
            printf("Possible");
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}