#include <bits/stdc++.h>

using namespace std;

long long solve(long long a){
    long long b = a/5*14;
    if(a%5==1)a=2;
    else if(a%5==2)a=6;
    else if(a%5==3)a=8;
    else if(a%5==4)a=10;
    else a=0;
    return a+b+1;
}
int main() {
    long long a;
    scanf("%lld",&a);
    printf("%lld\n",solve(a));
    return 0;
}