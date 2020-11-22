#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int k=2;
        for(int i=2; (1<<i)-1<=n; i++){
            if(n%((1<<i)-1)==0)k=i;
        }
        // printf("%d\n",k);
        printf("%d\n",n/((1<<k)-1));
        // printf("%d %d\n",k,n/((1<<k)-1));
    }
    return 0;
}