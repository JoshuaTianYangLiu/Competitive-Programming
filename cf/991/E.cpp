#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char in[20];
ll fac(int k){
    ll ret=1;
    for(int i=2; i<=k; i++)ret*=i;
    return ret;
}
int n;
int check[10];
int freq[10];
ll solve(){
    int m=0;
    for(int i=0; i<10; i++){
        m+=freq[i];
        if(check[i]!=0&&freq[i]==0)return 0;
    }
    printf("::%d\n",m);
    if(m==0)return 0;
    ll ret=fac(m-freq[0]);
    for(int i=1; i<10; i++){
        ret/=fac(freq[i]);
    }
    printf("%lld\n",ret);
    return ret;
}
int main() {
    scanf("%s",in);
    n=strlen(in);
    ll ans=0;
    for(int i=0; i<n; i++){
        check[in[i]-'0']++;
    }
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<10; j++)freq[j]=0;
        for(int j=0; j<n; j++){
            if((i&(1<<j))!=0){
                freq[in[j]-'0']++;
            }
        }
        printf("%d\n",i);
        for(int j=0; j<10; j++){
            printf("%d ",freq[j]);
        }
        printf("\n");
        ans+=solve();
    }
    printf("%lld\n",ans);
    return 0;
}