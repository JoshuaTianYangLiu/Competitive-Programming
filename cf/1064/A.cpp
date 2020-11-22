#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int m = min(a+b-1-c,min(a+c-b-1,b+c-1-a));
    printf("%d\n",-min(m,0));

    return 0;
}