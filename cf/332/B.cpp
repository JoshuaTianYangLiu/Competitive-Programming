#include <bits/stdc++.h>

using namespace std;
long long pp[200020];
long long ppp[200020];
long long in[200020];
int dumb[200020];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%lld",&in[i]);
        in[i]+=in[i-1];
        dumb[i]=i;
    }
    for(int i=1; i<=n-k+1; i++){
        pp[i]=in[i+k-1]-in[i-1];
        // printf("%lld ",pp[i]);
    }
    for(int i=n-k+1;i>0; i--){
        if(pp[i]<ppp[i+1]){
            ppp[i]=max(pp[i],ppp[i+1]);
            dumb[i]=dumb[i+1];
        }else{
            ppp[i]=pp[i];
        }
    }
    long long ans=0;
    int ree=0;
    for(int i=1; i<=n-k+1; i++){
        if(pp[i]+ppp[i+k]>ans){
            // printf("%d %d",i,i+k);
            ree=i;
            ans=pp[i]+ppp[i+k];
        }
    }
    printf("%d %d\n",ree,dumb[ree+k]);
    return 0;
}