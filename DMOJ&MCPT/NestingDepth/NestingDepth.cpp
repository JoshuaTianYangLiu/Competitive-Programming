#include <bits/stdc++.h>

using namespace std;
char in[110];
void printOpen(int a){
    while(a--)printf("(");
}
void printClose(int a){
    // printf("%d\n",a);
    while(a--)printf(")");
}
int main() {
    int t;
    scanf("%d\n",&t);
    for(int t1=1; t1<=t; t1++){
        scanf("%s",in);
        int len = strlen(in);
        printf("Case #%d: ",t1);
        int depth=0,a;
        for(int i=0; i<len; i++){
            char ac=in[i];
            a=ac-'0';
            if(a-depth>0){
                printOpen(a-depth);
            }else if(a-depth<0){
                printClose(depth-a);
            }
            depth=a;
            printf("%d",a);
        }
        if(depth>0)printClose(depth);

        printf("\n");
    }
    return 0;
}