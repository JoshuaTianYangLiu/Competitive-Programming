#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int ans=0,finalans=0,mm=0;
    int l=1;
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d",&a);
        ans+=a;
        mm=max(a,mm);
        if(ans<0){
            l=i+1;
            ans=0;
            mm=0;
        }
        if(ans-mm>finalans){
            // printf("%d %d %d\n",l,i,ans-mm);
            finalans=ans-mm;
        }
    }
    printf("%d\n",finalans);
    return 0;
}