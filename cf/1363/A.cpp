#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d %d",&n,&x);
        int odd=0,even=0;
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            if(a%2==0)even++;
            else odd++;
        }
        if(x%2==0){
            // odd*even+odd*odd;
            if(even==0){
                printf("No\n");
                continue;
            }
            int ee;
            if(even%2==0)ee=even-1;
            else ee=even;
            if(odd>=max((x-ee),1))printf("Yes\n");
            else printf("No\n");
        }else{
            // even*even+odd*odd;
            int ee = 2*(even/2);
            if(odd>=max((x-ee),1))printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}