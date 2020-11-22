#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,n;
        scanf("%d %d %d",&a,&b,&n);
        if(a>b)swap(a,b);
        int cnt=0;
        while(max(a,b)<=n){
            a+=b;
            swap(a,b);
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}