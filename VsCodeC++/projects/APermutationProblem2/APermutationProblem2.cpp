#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    if(k<=n/2){
        for(int i=n; i>n-k; i--)printf("%d ",i);
        for(int i=k+1; i<=n-k; i++)printf("%d ",i);
        for(int i=k; i>0; i--)printf("%d ",i);
    }else{
        k-=n/2;
        for(int i=n; i>k+1; i--)printf("%d ",i);
        for(int i=k; i>0; i--)printf("%d ",i);
        printf("%d ",k+1);
        // for(int i=)
    }
    return 0;
}
