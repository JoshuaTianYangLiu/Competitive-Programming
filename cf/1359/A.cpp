#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int a = min(n/k,m);
        int b = ceil((double)(m-a)/(k-1));
        printf("%d\n",a-b);
    }
    return 0;
}