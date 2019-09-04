#include <bits/stdc++.h>

using namespace std;
int f(int m,int n){
    if(m==0||n==0)return 0;
    int a=floor(log2(m)),b=floor(log2(n));
    int l=pow(2,min(a,b));
    return 1+f(l,n-l)+f(m-l,l)+f(m-l,n-l);
}
//l=1
//1+0+f(1,1)+0
int main() {
    for(int i=0; i<5; i++){
        int l,w;
        scanf("%d %d",&l,&w);
        printf("%d\n",f(l,w));
    }
    return 0;
}
