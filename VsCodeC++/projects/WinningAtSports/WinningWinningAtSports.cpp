#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
long long a[2000020];
long long fmp(long long n,int p){
  if(p==1)return n;
  if(p==0)return 1;
  if(p%2==0)return fmp(((n%MM)*(n%MM)%MM),p/2)%MM;
  return fmp(((n%MM)*(n%MM)%MM),p/2)%MM*n%MM;
}
long long cat(int n,int k){
    return ((a[n+k]*(n-k+1))%MM *fmp((a[k]*a[n+1])%MM,MM-2))%MM;
}
int main() {
    a[0]=1;
    for(int i=1; i<2000020; i++){
        a[i]=(i*a[i-1])%MM;
    }
    int size,c,b,d;
    // scanf("%d",&size);
    size=100000;
    d=size;
    while(size--){
        // scanf("%d-%d",&b,&c);
        b=rand();
        c=rand()%b;
        cat(b-1,c),cat(c,c);
        // printf("Case #%d: %lld %lld\n",d-size,cat(b-1,c),cat(c,c));
    }
}