#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a==0&&b==0&&c==0){
        if(d==4)printf("C1H4\n");
        else printf("invalid\n");
    }else if(b==0&&c==0){
        int e=2*(a+1)+2;
        if(e==d)printf("C%dH%d\n",a+1,d);
        else printf("invalid\n");
    }else if(a==0&&c==0){
        if(d==4)printf("C%dH%d\n",b+1,d);
        else printf("invalid\n");
    }else if(a==0&&b==0){
        if(c>1)printf("invalid\n");
        else if(d==2)printf("C2H2\n");
        else printf("invalid\n");
    }else{
        printf("invalid\n");
    }
    // if(c<2){
    //     int numOfC=a+b+c+1;
    //     int numOfH=2+
    // }
    return 0;
}