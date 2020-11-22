#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char in[1000010];
int freq[30];
int main() {
    scanf("%s",in);
    int cnt=0;
    int n=strlen(in);
    for(int i=0; i<n; i++){
        int a=in[i];
        // printf("%d",a);
        freq[a-'A']++;
    }
    for(int a:freq){
        // printf("%d ",a);
        if(a%2){
            cnt++;
        }
    }
    if(cnt>1){
        printf("NO SOLUTION\n");
        return 0;
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<freq[i]/2; j++)printf("%c",i+'A');
    }
    for(int i=0; i<26; i++){
        if(freq[i]%2)printf("%c",i+'A');
    }
    for(int i=25; i>=0; i--){
        for(int j=0; j<freq[i]/2; j++)printf("%c",i+'A');
    }
    return 0;
}