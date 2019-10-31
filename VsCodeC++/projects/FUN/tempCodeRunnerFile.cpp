#include <bits/stdc++.h>

using namespace std;
char in[100010];
int charCnt[27];
int main() {
    int k;
    scanf("%s\n%d",in,&k);
    int l=0;
    int ans=0;
    for(int i=0; i<strlen(in); i++){
        int t=in[i]-'a';
        if(charCnt[t]+1>k){
            while(charCnt[t]+1>k){
                // printf("%d %d\n",l,i-1);
                ans+=i-l;
                charCnt[in[l]-'a']--;
                l++;
            }
        }
        charCnt[t]++;
    }
    while(l<strlen(in)){
        // printf("%d %d\n",l,strlen(in)-1);
        ans+=strlen(in)-l;
        charCnt[in[l]-'a']--;
        l++;
    }
    printf("%d",ans);
    return 0;
}
