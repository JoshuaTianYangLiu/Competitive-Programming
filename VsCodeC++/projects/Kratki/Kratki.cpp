#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    if(2*k<n)printf("-1");
    else{
        int comp=n-k;
        for(int i=1; i<=k; i++){
            printf("%d ",i);
            if(n-i+1>k)printf("%d ",n-i+1);
        }
    }
    return 0;
}
