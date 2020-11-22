#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int prev=2e9;
    for(int i=0; i<n; i++){
        int w,h;
        scanf("%d %d",&w,&h);
        if(max(w,h)<=prev)prev=max(w,h);
        else if(min(w,h)<=prev)prev=min(w,h);
        else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}