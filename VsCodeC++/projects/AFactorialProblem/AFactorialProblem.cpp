#include <bits/stdc++.h>

using namespace std;
int calc(int n){
    int i=5;
    int sum=0;
    while(i<=n){
        sum+=n/i;
        i*=5;
    }
    return sum;
}
int main() {
    int q;
    scanf("%d",&q);
    if(q==0){
        printf("1\n");
        return 0;
    }
    int l=0,r = 405175790,m;
    while(l<=r){
        m = (l+r)/2;
        if(calc(m)==q)break;
        else if(q<calc(m)) r=m-1;
        else l=m+1;
    }
    m/=5; m*=5;
    if(calc(m)==q)printf("%d\n",m);
    else printf("No solution\n");
    return 0;
}