#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,n;
    scanf("%d %d %d %d",&a,&b,&c,&n);
    if(c>a||c>b){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",(n-a-b+c)>0?n-a-b+c:-1);
    return 0;
}