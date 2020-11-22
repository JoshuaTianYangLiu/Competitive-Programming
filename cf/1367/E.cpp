#include <bits/stdc++.h>

using namespace std;
vector<int> pf[2010];
bool check[2010];
char in[2010];
int freq[30];
int main() {
    for(int i=2; i<2010; i++){
        if(!check[i]){
            for(int j=i; j<2010; j+=i){
                pf[j].push_back(i);
                check[j]=true;
            }
        }
    }
    // for(int i=1; i<2010; i++)pf[i].push_back(1);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(freq,0,sizeof(freq));
        int n,k;
        scanf("%d %d",&n,&k);
        scanf("%s",in);
        int m=strlen(in);
        for(int i=0; i<m; i++){
            freq[in[i]-'a']++;
        }
        sort(freq,freq+30);
        int finalAns=0;
        int ans=0;
        // for(int i=0; i<30; i++){
        //     printf("%d ",freq[i]);
        // }
        // printf("\n");
        for(int p:pf[k]){
            // printf(":::%d\n",p);
            // printf("Freq %d %d\n",freq[30-p],freq[30-p]*p));
            ans=max(ans,freq[30-p]*(p));
            finalAns=max(finalAns,ans);
            ans=0;
            int pos;
            for(int i=29; i>=0; i--){
                pos=i;
                if(freq[i]>=p)ans=freq[i]/p;
                else break;
            }
            // printf("ANS %d %d\n",ans,ans*p*(29-pos));
            finalAns=max(finalAns,ans*p*(29-pos));
        }
        printf("%d\n",finalAns);
    }
    return 0;
}