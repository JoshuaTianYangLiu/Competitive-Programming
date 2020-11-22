#include <bits/stdc++.h>

using namespace std;
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101};
int facList[27];
int charList[26];
char a[111],b[111];
int main() {
    scanf("%s\n%s",a,b);
    for(int i=0; i<strlen(b); i++)charList[b[i]-'a']++;
    for(int i=0; i<strlen(a); i++){
        charList[a[i]-'a']--;
        if(charList[a[i]-'a']<0){
            printf("0\n");
            return 0;
        }
    }
    for(int k=2; k<=strlen(b)-strlen(a)+1; k++){
        int i=k;
        int j=0;
        while(i!=1){
            if(primes[j]!=0&&i%primes[j]==0){
                facList[j]++;
                i/=primes[j];
            }else{
                j++;
            }
        }
    }
    for(int k=0;k<26; k++){
        for(int l=2; l<=charList[k]; l++){
            int i=l;
            int j=0;
            while(i!=1){
                if(primes[j]!=0&&i%primes[j]==0){
                    facList[j]--;
                    i/=primes[j];
                }else{
                    j++;
                }
            }
        }
    }
    long long ans=1;
    for(int i=0; i<27; i++){
        while(facList[i]-->0){
            ans*=primes[i];
            ans%=1000000007;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
