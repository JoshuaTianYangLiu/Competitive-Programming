#include <bits/stdc++.h>

using namespace std;
int in[3010],inSort[3010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&in[i]);
            inSort[i]=in[i];
        }
        sort(inSort+1,inSort+1+n);
        int ans=0;
        for(int i=1; i<=n; i++){
            int pos=i;
            for(int j=1; j<=n; j++){
                if(in[j]==inSort[pos])pos++;
                if(pos>n)break;
            }
            ans=max(ans,pos-i);
            // printf("%d %d %d\n",pos-i,i,pos);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}