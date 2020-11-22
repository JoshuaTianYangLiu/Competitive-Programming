#include <bits/stdc++.h>

using namespace std;
char in[110];
int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",in);
        int len=strlen(in);
        if(len<=10){
            printf("%s\n",in);
            continue;
        }
        printf("%c%d%c\n",in[0],len-2,in[len-1]);
    }
    return 0;
}