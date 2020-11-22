#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x,m;
        scanf("%d %d %d",&n,&x,&m);
        int u=x,d=x;
        for(int i=0,l,r; i<m; i++){
            scanf("%d %d",&l,&r);
            if(r>=d)d=min(l,d);
            if(l<=u)u=max(r,u);
        }
        printf("%d\n",u-d+1);
    }
    return 0;
}