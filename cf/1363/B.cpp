#include <bits/stdc++.h>

using namespace std;
char in[1010];
int psa[1010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        int len = strlen(in);
        for(int i=0; i<len; i++){
            if(i==0)psa[i]=in[i]-'0';
            else psa[i]=in[i]-'0'+psa[i-1];
        }
        int ans=1e9;
        for(int i=0; i<len; i++){
            ans=min(ans,i+1-psa[i]+psa[len-1]-psa[i]);
            // printf("::%d %d\n",i+1-psa[i],psa[len-1]-psa[i]);
            ans=min(ans,psa[i]+len-i-1-psa[len-1]+psa[i]);
            // printf("::%d %d\n",psa[i],len-i-1-psa[len-1]+psa[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}