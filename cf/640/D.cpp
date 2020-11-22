#include <bits/stdc++.h>

using namespace std;
int in[1010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(in,0,sizeof(in));
        int n,a=0,b=0,moves=0,ate=0,aate=0;
        bool lturn=false;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&in[i]);
        for(int l=1,r=n;l<=r;){
            ate=aate;
            aate=0;
            while(ate>=aate&&l<=r){
                if(!lturn){
                    aate=0;
                    moves++;
                    lturn=true;
                }
                aate+=in[l];
                a+=in[l++];
                // printf("%d %d\n",ate,a);
            }
            ate=aate;
            aate=0;
            while(ate>=aate&&l<=r){
                if(lturn){
                    aate=0;
                    moves++;
                    lturn=false;
                }
                aate+=in[r];
                b+=in[r--];
                // printf("::%d %d\n",ate,b);
            }
        }
        printf("%d %d %d\n",moves,a,b);
    }
    return 0;
}