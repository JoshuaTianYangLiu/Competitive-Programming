#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int maxVal=0;
        long long ans=0;
        for(int i=0,a; i<n; i++){
            scanf("%d",&a);
            if(maxVal==0)maxVal=a;
            if(a<0){
                if(maxVal>0){
                    ans+=maxVal;
                    maxVal=a;
                }else{
                    maxVal=max(maxVal,a);
                }
            }else{
                if(maxVal<0){
                    ans+=maxVal;
                    maxVal=a;
                }else{
                    maxVal=max(maxVal,a);
                }
            }
        }
        ans+=maxVal;
        printf("%lld\n",ans);
    }
    return 0;
}