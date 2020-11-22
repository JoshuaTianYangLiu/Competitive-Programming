#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int ans=0;
    int train=0;
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        train+=b-a;
        ans=max(ans,train);
    }
    printf("%d\n",ans);
    return 0;
}