#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c;
    scanf("%d %d:%d",&a,&b,&c);
    // printf("%d %d %d\n",a,b,c);
    int d=(int)round(-a+(60*b+c)/4.0);
    if(d<0)d+=720;
    d%=360;
    d=360-d;
    if(d<0)d+=720;
    d%=360;
    printf("%d",d);
    return 0;
}