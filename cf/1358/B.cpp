#include <bits/stdc++.h>

using namespace std;
int in[200020];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&in[i]);
        sort(begin(in)+1,begin(in)+n+1);
        int ans=1;
        // int snans=0;
        for(int i=1; i<=n; i++){
            if(in[i]<=i){
                ans=i+1;
                // snans=ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}