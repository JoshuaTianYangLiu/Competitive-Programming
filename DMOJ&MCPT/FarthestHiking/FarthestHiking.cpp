#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,d,e;
    scanf("%d %d %d %d %d\n",&a,&b,&c,&d,&e);
    char in;
    for(int i=0; i<b; i++){
        scanf("%c",&in);
        while(in=='\n')scanf("%c",&in);
        if(in=='f'){
            if(a-2*d>=0)a-=2*d;
            else{
                printf("%d",i);
                return 0;
            }
        }else{
            if(a-c-e>=0)a-=c+e;
            else{
                printf("%d",i);
                return 0;
            }
        }
    }
    printf("%d",b);
    return 0;
}
