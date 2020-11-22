#include <bits/stdc++.h>

using namespace std;
char in[1010];
int main() {
    scanf("%s\n",in);
    char split;
    scanf("%c",&split);
    int a=strlen(in);
    for(int i=0; i<a; i++){
        if(in[i]==split&&i!=a-1)printf("\n");
        if(in[i]!=split)printf("%c",in[i]);
    }
    return 0;
}