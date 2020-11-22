#include <bits/stdc++.h>

using namespace std;
char in[200010];
int psa[200010];
int q(int r,int l){return psa[r]-psa[l-1];}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(psa,0,sizeof(psa));
        int n,k;
        scanf("%d %d",&n,&k);
        scanf("%s",in+1);
        int ans=0;
        for(int i=1; i<=n; i++){
            psa[i]=psa[i-1]+in[i]-'0';
        }
        for(int i=1; i<=n; i++){
            if(q(i,max(i-k,1))==0&&q(min(i+k,n),i)==0){
                ans++;
                // printf(":::%d\n",i);
                i+=k;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}