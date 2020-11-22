#include <bits/stdc++.h>

using namespace std;
int in[200020];
int freq[400040];
int update(int l,int r,int v){
    freq[l]+=v;
    freq[r+1]-=v;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(freq,0,sizeof(freq));
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=1; i<=n; i++){
            scanf("%d",&in[i]);
        }
        for(int i=1; i<=n/2; i++){
            int a = in[i],b=in[n-i+1];
            update(2,min(a,b),2);
            update(max(a,b)+k+1,2*k,2);
            update(min(a,b)+1,a+b-1,1);
            update(a+b+1,max(a,b)+k,1);
        }
        int ans=1e9;
        for(int i=2; i<=2*k; i++){
            freq[i]+=freq[i-1];
            ans=min(ans,freq[i]);
            // printf("%d ",freq[i]);
        }
        printf("%d\n",ans);

    }
    return 0;
}