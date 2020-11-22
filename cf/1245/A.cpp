#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(__gcd(a,b)!=1)printf("Infinite\n");
        else printf("Finite\n");
    }
    return 0;
}