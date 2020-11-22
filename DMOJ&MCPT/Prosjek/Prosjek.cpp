#include <bits/stdc++.h>

using namespace std;
int in[300010];
long long psa[300010];
int n,k;
bool fine(int x){
    long long mi=0;
    for(int i=1; i<=n; i++){
        psa[i]=psa[i-1]+in[i]-x;
        if(i>=k){
            mi=min(mi,psa[i-k]);
            if(psa[i]-mi>=0)return true;
        }
    }
    return false;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
        in[i]*=1000;
    }
    int l=0,h=1e9,ans=0;
    while(l<=h){
        int m = (l+h)/2;
        if(fine(m)){
            ans=m;
            l=m+1;
        }else{
            h=m-1;
        }
    }
    printf("%.4f\n",ans/1000.0);
    return 0;
}