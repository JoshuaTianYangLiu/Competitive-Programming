#include <bits/stdc++.h>

using namespace std;
char in[110];
int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",in);
        int m=strlen(in);
        printf("%c",in[0]);
        for(int i=1; i<m; i+=2)printf("%c",in[i]);
        printf("\n");
    }
    return 0;
}