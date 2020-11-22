#include <bits/stdc++.h>

using namespace std;
int memo[25820];
int main() {
    int t;
    scanf("%d",&t);
    for(int i=0; i<25820; i++){
        memo[i]=(3*i*i+7*i+4)/2;
        // printf("%d\n",memo[i]);
    }
    while(t--){
        int n,ans=0;
        scanf("%d",&n);
        while(n>1){
            int m=lower_bound(begin(memo),end(memo),n+1)-begin(memo)-1;
            // printf("::%d %d %d\n",n,m,memo[m]);
            n-=memo[m];
            ans++;
        }
        // printf("%d %d\n",ans,n);
        printf("%d\n",ans);
    }
    return 0;
}

/*
2 7 15
 5 8  11
2 + sum(3*i+2)1-n
2 + 2n+n*(n+1)/2
*/