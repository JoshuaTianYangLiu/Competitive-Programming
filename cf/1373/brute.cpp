#include <bits/stdc++.h>

using namespace std;
char in[1000010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(in,0,sizeof(in));
        scanf("%s",in);
        int n=strlen(in);
        long long ans=0;
        for(int i=0; i<1000; i++){
            int cur=i;
            bool ree=true;
            for(int i=0; i<n; i++){
                ans++;
                if(in[i]=='+')cur++;
                else cur--;
                if(cur<0){
                    ree=false;
                    break;
                }
            }
            if(ree) break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}