#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1");
        return 0;
    }
    if(n<=3){
        printf("NO SOLUTION\n");
        return 0;
    }
    if(n==4){
        printf("2 4 1 3");
        return 0;
        // Get scammed
    }
    for(int i=2*(n/2); i>0; i-=2)printf("%d ",i);
    for(int i=n%2==0?n-1:n; i>0; i-=2)printf("%d ",i);
    return 0;
}