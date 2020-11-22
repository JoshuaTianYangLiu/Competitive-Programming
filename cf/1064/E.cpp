#include <bits/stdc++.h>

using namespace std;
char in[10];
int main() {
    int n;
    scanf("%d",&n);
    char bot='a';
    int l=0,r=1e9;
    printf("0 0\n");
    fflush(stdout);
    scanf("%s",in);
    bot=in[0];
    int m;
    int lb=l,rb=r;
    if(n==30){
        for(int i=1; i<n-1; i++){
            lb=l,rb=r;
            m=(l+r)/2;
            printf("%d 0\n",m,m);
            fflush(stdout);
            scanf("%s",in);
            if(in[0]==bot){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        lb=l,rb=r;
        if(in[0]==bot)lb--;
        // else rb++;
        // m=(l+r)/2;
        int mm=1e5;
        printf("%d 100\n",mm);
        fflush(stdout);
        scanf("%s",in);
        if(in[0]==bot)printf("%d 100 %d 0\n",mm+1,lb+1);
        else printf("%d 100 %d 0\n",mm-1,lb+1);
    }else{
        for(int i=1; i<n; i++){
            m=(l+r)/2;
            printf("%d 0\n",m);
            fflush(stdout);
            scanf("%s",in);
            if(in[0]==bot){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        m=(l+r)/2;
        printf("%d 0 %d 1\n",m,m);
    }
    return 0;
}