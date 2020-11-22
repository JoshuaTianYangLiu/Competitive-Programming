#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    int w=0,x=INT_MAX,y=0,z=INT_MAX;
    for(int i=0,m; i<n; i++){
        scanf("%d",&m);
        w=max(w,m-i);
        x=min(x,m-i);
        y=max(y,m+i);
        z=min(z,m+i);
    }
    printf("%d",max(w-x,y-z));
    return 0;
}
