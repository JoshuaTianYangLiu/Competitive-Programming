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
        int cnt=0,cur=0;
        for(int i=0; i<n; i++){
            char a=in[i];
            if(a=='-'){
                cur--;
                if(cur<0){
                    cur=0;
                    ans+=i+1;
                }
            }else{
                cur++;
            }
        }
        ans+=n;
        printf("%lld\n",ans);
    }
    return 0;
}