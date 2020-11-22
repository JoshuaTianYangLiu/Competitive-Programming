#include <bits/stdc++.h>

using namespace std;
char a[2001];
char b[2001];
int main() {
    scanf("%s\n%s",a,b);
    int l = strlen(a);
    for(int i=0; i<l; i+=2){
        int x=(a[i]-'0')*10+a[i+1]-'0';
        int y=(b[i]-'0')*10+b[i+1]-'0';
        printf("%c",(char)(y-x+'A'-1));
    }
    return 0;
}
