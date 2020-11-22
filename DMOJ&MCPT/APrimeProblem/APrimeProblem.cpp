#include <bits/stdc++.h>

using namespace std;
bool isPrime(int n){
    // printf("%d\n",n);
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    int d,n;
    scanf("%d %d",&d,&n);
    for(int i=max((int)pow(10,d),n);;i++){
        for(int j=d; j<=(int)log10(i)-d; j++){
            int a=round(pow(10,j));
            // printf("%d %d %d\n",a,i/a,i%a);
            if(isPrime(i/a)&&isPrime(i%a)){
                printf("%d\n",i);
                return 0;
            }
        }
    }
    return 0;
}