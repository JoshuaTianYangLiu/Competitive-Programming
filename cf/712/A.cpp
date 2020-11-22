#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int b,a;
    scanf("%d",&b);
    for(int i=1; i<n; i++){
        scanf("%d",&a);
        printf("%d ",a+b);
        b=a;
    }
    printf("%d\n",b);
    return 0;
}