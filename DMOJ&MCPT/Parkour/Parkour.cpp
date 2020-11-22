#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,w,h,n;
    scanf("%d %d %d %d %d",&x,&y,&w,&h,&n);
    int a=0,b=0;

    while(--n){
        if(((x-a==y-b&&w>h)||x-a>y-b)&&a+2<x+w){
            a+=2;b++;
        }else{
            b+=2;a++;
        }
        if(a>=x&&b>=y&&a<x+w&&b<y+h){
            printf("YES\n");
            return 0;
        }
    }
    if(a>=x&&b>=y&&a<x+w&&b<y+h)printf("YES\n");
    else printf("NO\n");
    // printf("\n%d %d",a,b);
}
