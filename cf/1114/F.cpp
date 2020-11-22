#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,x,y,z;
    scanf("%d %d %d %d %d %d",&x,&y,&z,&a,&b,&c);
    a-=x;
    if(a<0){
        printf("NO\n");
    }else{
        if(a<=y){
            y-=a;
            a=0;
            b-=y;
        }else{
            a-=y;
        }
        if(b<0)printf("NO\n");
        else{
            int tot=a+b+c;
            tot-=z;
            if(tot<0)printf("NO\n");
            else printf("YES\n");
        }

    }
    return 0;
}