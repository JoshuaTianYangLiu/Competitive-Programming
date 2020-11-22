#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
long long cat[4005];
//3000-4000?
//Q = 1000?
int main() {
    cat[0]=1;
    for(int i=1; i<4005; i++){
        int sum=0;
        for(int j=0; j<i; j++){
            sum+=(cat[j]*cat[i-j-1])%MM;
            sum%=MM;
        }
        cat[i]=sum;
    }
    int q;
    scanf("%d",&q);
    for(int i=0,a; i<q; i++){
        scanf("%d",&a);
        printf("%d\n",cat[a]);
    }
    return 0;
}
