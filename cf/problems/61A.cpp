#include <bits/stdc++.h>

using namespace std;
char a[110],b[110];
int main() {
    scanf("%s\n%s",a,b);
    for(int i=0; i<strlen(a); i++){
        if(a[i]=='1'^b[i]=='1')printf("1");
        else printf("0");
    }
    return 0;
}