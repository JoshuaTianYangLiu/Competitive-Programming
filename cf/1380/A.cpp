#include <bits/stdc++.h>

using namespace std;
int in[1010];
int pre[1010],suf[1010];
int idx[1010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d\n",in[i]);
            idx[in[i]]=i;
        }
        pre[0]=1e9;
        for(int i=1; i<=n; i++){
            pre[i]=min(pre[i-1],in[i]);
        }
        for(int i=n; i>0; i--){
            suf[i]=min(suf[i+1],in[i]);
        }
        bool ree=false;
        for(int i=2; i<n; i++){
            if(in[i]>pre[i-1]&&in[i]>suf[i+1]){
                printf("YES\n");
                printf("%d %d %d\n",idx[pre[i-1]],i,idx[suf[i+1]]);
                ree=true;
                break;
            }
        }
        if(!ree)printf("NO\n");
    }
    return 0;
}