#include <bits/stdc++.h>

using namespace std;
char in[110];
bool isVowel(char a){
    return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
}
int main() {
    scanf("%s",in);
    int n=strlen(in);
    for(int i=0; i<n-1; i++){
        if(!isVowel(in[i])&&!isVowel(in[i+1])&&in[i]!='n'){
            printf("NO\n");
            return 0;
        }
    }
    if(isVowel(in[n-1])||in[n-1]=='n')printf("YES\n");
    else printf("NO\n");
    return 0;
}