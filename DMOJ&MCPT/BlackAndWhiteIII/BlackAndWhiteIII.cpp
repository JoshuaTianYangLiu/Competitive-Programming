#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
#define MMM 1000000006
int fmp(long long b,int pow){
    if(pow==1)return b;
    if(pow==0)return 1;
    if(pow%2==0)return fmp((b*b)%MM,pow/2)%MM;
    return (b*fmp((b*b)%MM,pow/2))%MM;
}
int fmp1(long long b,int pow){
    if(pow==1)return b;
    if(pow==0)return 1;
    if(pow%2==0)return fmp1((b*b)%MMM,pow/2)%MMM;
    return (b*fmp1((b*b)%MMM,pow/2))%MMM;
}
int main() {
    int k,m;
    scanf("%d %d",&k,&m);
    char a;
    long long cnt=0;
    k=fmp(2,k*2);
    while(k){
        scanf("%c",&a);
        while(a=='\n'||a==' ')scanf("%c",&a);
        if(a=='#')cnt++;
        k--;
    }
    int l=fmp1(4,m);
    l=fmp(2,l)-1;
    l=fmp(l,cnt);
    printf("%d",l);
    return 0;
}
