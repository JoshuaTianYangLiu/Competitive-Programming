#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        if((n-2*k+2)%2==0&&n-2*k+2>0){
            printf("YES\n");
            for(int i=1; i<k; i++)printf("2 ");
            printf("%d\n",n-2*k+2);
        }else if((n-k+1)%2==1&&n-k+1>0){
            printf("YES\n");
            for(int i=1; i<k; i++)printf("1 ");
            printf("%d\n",n-k+1);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}