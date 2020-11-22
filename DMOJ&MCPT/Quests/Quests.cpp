#include <bits/stdc++.h>

using namespace std;
long long dpPre[5050],dpCur[5050];
int main() {
    int n,h;
    scanf("%d %d",&n,&h);
    for(int i=0,a,b,c,d; i<n; i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        memset(dpCur,0,sizeof(dpCur));
        for(int j=b; j<=h; j++){
            dpCur[j]=dpPre[j-b]+a;
        }
        for(int j=b+d; j<=h; j++){
            dpCur[j]=max(dpCur[j],dpCur[j-d]+c);
        }
        for(int j=0; j<=h; j++){
            dpPre[j]=max(dpPre[j],dpCur[j]);
        }
    }
    printf("%lld",dpPre[h]);
    return 0;
}
//1 0 Knapsack
//Unlimited Knapsack
//Combine both arrays
//Work this out write it out