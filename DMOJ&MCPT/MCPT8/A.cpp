#include <bits/stdc++.h>

using namespace std;
int price[] ={1, 2, 5, 10, 20, 50, 100};
long long ans[7];
int main() {
    int n;
    long long a;
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&a);
        long long b=0;
        for(int i=6; i>=0; i--){
            ans[i]=a/price[i];
            b+=a/price[i];
            a%=price[i];
        }
        printf("%lld\n",b);
        for(int i=0; i<7; i++){
            printf("%lld ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}