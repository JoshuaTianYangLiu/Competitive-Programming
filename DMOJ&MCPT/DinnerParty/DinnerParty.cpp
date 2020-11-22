#include <bits/stdc++.h>

using namespace std;
int in[1000010],diff[1000010];
int main() {
    // freopen("debug.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
        if(i>0)diff[i]=in[i]-in[i-1];
    }
    diff[0]=in[0]-in[n-1];
    int aaa=0;
    for(int i=1; i<n; i++){
        aaa+=diff[i];
    }
    
    return 0;
}