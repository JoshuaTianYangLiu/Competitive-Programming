#include <bits/stdc++.h>

using namespace std;
char in[1000010];
int arr[1000010];
int ss(int l,int r){
    return arr[r]-arr[l-1];
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        scanf("%s",in+1);
        for(int i=1; i<=n; i++){
            arr[i]=in[i]-'0';
            arr[i]+=arr[i-1];
        }
        if(k==1){
            int tot=arr[n];
            int ll=0,lsl=0;
            for(int i=1; i<=n; i++){
                if(in[i]=='1'){
                    lsl++;
                }else{
                    ll=max(ll,lsl);
                    lsl=0;
                }
            }
            ll=max(ll,lsl);
            printf("%d\n",tot-ll);
            continue;
        }
        // for(int i=0; i<=n; i++)printf("%c",in[i]);
        // printf("\n");
        int finalAns=1e9;
        for(int i=1; i<=k; i++){
            bool landedOne=false;
            int ans=arr[i-1];
            int buf=0;
            int j=i;
            for(; j<=n; j+=k){
                if(j-k+1>0)ans+=ss(j-k+1,j-1);
                else ans+=ss(1,j-1);
                // printf("%d %d %d\n",j-k+1,j-1,ans);
                // printf("%d %d %c\n",j,ans,in[j]);
                if(in[j]=='1'){
                    landedOne=true;
                    ans+=buf;
                    buf=0;
                }else{
                    if(landedOne)buf++;
                }
            }
            j-=k;
            ans+=ss(j+1,n);
            finalAns=min(finalAns,ans);
        }
        printf("%d\n",finalAns);
    }
    return 0;
}
