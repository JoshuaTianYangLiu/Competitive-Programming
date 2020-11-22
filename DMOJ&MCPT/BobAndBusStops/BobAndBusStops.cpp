#include <bits/stdc++.h>

using namespace std;
int in[100010];
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    sort(in+1,in+1+n);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        l=lower_bound(in+1,in+1+n,l)-(in+1);
        r=upper_bound(in+1,in+1+n,r)-(in+1);
        printf("%d\n",r-l);
    }
    return 0;
}