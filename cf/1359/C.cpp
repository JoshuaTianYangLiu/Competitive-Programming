#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int h,c,t;
double calc(ll x){
    return (h*(x+1)+c*x)/(double)(2*x+1);
}
int main() {
    int tt;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d %d %d",&h,&c,&t);
        if(h==t){
            printf("1\n");
            continue;
        }
        if((h+c)/2>=t){
            printf("2\n");
            continue;
        }
        ll l=1,r=1+1e12,m;
        double sofar=h,cm;
        while(l<r){
            // printf("::%lld %lld\n",l,r);
            m=(l+r)/2;
            // printf("%lld\n",m);
            cm = calc(m);
            if(cm<t){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        ll ans=0;
        double cans=0;
        for(ll i=l-5; i<r+5; i++){
            if(abs(t-calc(i))<abs(t-cans)){
                ans=i;
                cans=calc(i);
            }
        }
        printf("%lld\n",2*ans+1);
        // printf("%lld %lld\n",l,r);
        // printf("%.6lf %.6lf %.6lf %.6lf\n",calc(l),calc(r),calc(l+2),calc(r-2));
        
    }
    return 0;
}