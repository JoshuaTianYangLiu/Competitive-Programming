#include <bits/stdc++.h>

using namespace std;

int main() {
    int l=1,r=2e9+1;
    char a[10];
    while(l<=r){
        int m=l+(r-l)/2;
        printf("%d\n",m);
        scanf("%s",a);
        if(a[0]=='O'){
            return 0;
        }else if(a[0]=='S'){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return 0;
}