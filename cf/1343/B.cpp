#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n%4!=0){
            printf("NO\n");
        }else{
            printf("YES\n");
            long long cnt=0;
            for(int i=1; i<=n/2; i++){
                cnt+=2*i;
                printf("%d ",2*i);
            }
            for(int i=1; i<n/2; i++){
                cnt-=2*i-1;
                printf("%d ",2*i-1);
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}