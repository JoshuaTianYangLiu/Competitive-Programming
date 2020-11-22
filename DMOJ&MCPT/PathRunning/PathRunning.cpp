#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    int start=1;
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        if(start+k==i){
            if(a==1)start+=k;
            else{
                printf("NO\n");
                return 0;
            }
        }
    }
    if(start==n)printf("YES\n");
    else printf("NO\n");
    return 0;
}