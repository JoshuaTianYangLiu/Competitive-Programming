#include <bits/stdc++.h>

using namespace std;
int ans[110];
int main() {
    int t,b;
    scanf("%d %d",&t,&b);
    while(t--){
        int query=1,dummyVal;
        for(int i=1; i<=b; i++){
            if(query%10==1){
                query++;
                printf("1\n");
                scanf("%d",&dummyVal);
            }
            query++;
            printf("%d\n",i);
            scanf("%d",&ans[i]);
        }
        for(int i=1; i<=b; i++){
            printf("%d",ans[i]);
        }
        printf("\n");
        char verdict;
        scanf("%c",&verdict);
        if(verdict=='N')return 0;
    }
    return 0;
}