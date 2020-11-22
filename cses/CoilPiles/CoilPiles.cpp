#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        // printf("%d %d\n",(2*b-a)%3,(2*a-b)%3);
        if((2*a-b)%3||(2*b-a)%3||(2*b-a)<0||(2*a-b)<0){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}