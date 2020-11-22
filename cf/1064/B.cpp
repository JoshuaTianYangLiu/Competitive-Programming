#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a;
        scanf("%d",&a);
        // int cnt=0;
        // for(int i=0; i<=a; i++){
        //     if(a-(a^i)-i==0){
        //         // printf("::%d\n",i);
        //         cnt++;
        //     }
        // }
        printf("%d\n",(1<<__builtin_popcount(a)));
        // printf("::%d %d\n",__builtin_popcount(a),cnt);
    }
    return 0;
}