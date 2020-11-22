#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int m=k-(n-1)*(k/(n-1));
        int placement=m+n*(k/(n-1));
        if(placement%n==0)placement--;
        printf("%d\n",placement);
    }
    return 0;
}
//