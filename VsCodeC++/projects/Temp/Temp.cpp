#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
long long cat[3005];
int main() {
    freopen("output1.out","w",stdout);
    freopen("input1.in","r",stdin);
    cat[0]=1;
    for(int i=1; i<3005; i++){
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
    fclose(stdout);
    fclose(stdin);
    return 0;
}