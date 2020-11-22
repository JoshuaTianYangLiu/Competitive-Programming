#include <bits/stdc++.h>

using namespace std;
char a[110],b[110],c[110];
char freq[27];
int main() {
    scanf("%s\n%s\n%s",a,b,c);
    int n=strlen(a),m=strlen(b),o=strlen(c);
    for(int i=0; i<n; i++)freq[a[i]-'A']++;
    for(int i=0; i<m; i++)freq[b[i]-'A']++;
    for(int i=0; i<o; i++)freq[c[i]-'A']--;
    for(int i=0; i<27; i++){
        if(freq[i]!=0){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}