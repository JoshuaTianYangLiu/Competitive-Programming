#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    int a,b,c;
    int ret=0;
    a=b=c=y;
    while(a!=x||b!=x||c!=x){
        a=min(x,b+c-1);
        ret++;
        if(a==x&&b==x&&c==x)break;
        b=min(x,a+c-1);
        ret++;
        if(a==x&&b==x&&c==x)break;
        c=min(x,a+b-1);
        ret++;
        if(a==x&&b==x&&c==x)break;
    }
    printf("%d\n",ret);
    return 0;
}