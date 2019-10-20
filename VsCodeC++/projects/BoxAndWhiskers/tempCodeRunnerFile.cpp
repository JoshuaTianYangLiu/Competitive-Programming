#include <bits/stdc++.h>

using namespace std;
int in[100005];
double f(int a,int b){
    if((b+a)%2==0)return in[(a+b)/2];
    else return (in[(a+b)/2]+in[((a+b)/2)+1])/2.0;
}
int main() {
    int n,mi=10e7,ma=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
        mi=min(mi,in[i]);
        ma=max(ma,in[i]);
    }
    printf("%d %d ",mi,ma);
    double a=f(1,n/2),b=f(1,n),c=f(n+1-n/2,n);
    if(a==(int)a)printf("%.0f ",a);
    else printf(".1f ",a);
    if(b==(int)b)printf(".0f ",b);
    else printf(".1f ",b);
    if(c==(int)c)printf(".0f ",c);
    else printf(".1f ",c);
    return 0;
}