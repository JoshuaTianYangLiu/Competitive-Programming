#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,h,a,b,k;
    scanf("%d %d %d %d %d",&n,&h,&a,&b,&k);
    while(k--){
        int ta,fa,tb,fb;
        scanf("%d %d %d %d",&ta,&fa,&tb,&fb);
        if(ta==tb){
            printf("%d\n",abs(fa-fb));
        }else{
            int ans=0;
            int x=min(max(a,fa),b);
            ans=abs(fa-x)+abs(fb-x);
            printf("%d\n",abs(ta-tb)+ans);
        }
    }
    return 0;
}