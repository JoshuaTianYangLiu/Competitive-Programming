#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long x,y;
        scanf("%lld %lld",&y,&x);
        long long square = max(x,y);
        long long diff=0;
        if(square%2==0){
            diff=x+square-y;
        }else{
            diff=y+square-x;
        }
        printf("%lld\n",square*square-diff+1);

    }
    return 0;
}