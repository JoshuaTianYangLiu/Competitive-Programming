#include <bits/stdc++.h>

using namespace std;
char charList[27];
char in[1000010];
unordered_map<string,int> um;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        memset(charList,0,sizeof(charList));
        int cnt='a';
        scanf("%s",in);
        int l=strlen(in);
        for(int j=0; j<l; j++){
            if(charList[in[j]-'A']==0){
                charList[in[j]-'A']=cnt++;
            }
            in[j]=charList[in[j]-'A'];
        }
        um[in]++;
    }
    long long ans=0;
    for(auto t:um){
        long long u=t.second-1;
        ans+=(u*(u+1))/2;
    }
    printf("%lld\n",ans);
    return 0;
}
