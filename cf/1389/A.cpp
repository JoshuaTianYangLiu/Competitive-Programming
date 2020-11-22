#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d %d",&l,&r);
        int x = l;
        int y = 2*x;
        if(y<=r){
            printf("%d %d\n",x,y);
        }else{
            printf("-1 -1\n");
        }
    }
    return 0;
}