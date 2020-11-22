#include <bits/stdc++.h>

using namespace std;
int in[1000010][27];
int main() {
    char a='a';
    for(int i=1; a!='\n'; i++){
        scanf("%c",&a);
        if(a!=' '&&a!='\n')in[i][a-'a']++;
        for(int j=0; j<27; j++){
            in[i][j]+=in[i-1][j];
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int n,m;
        char o;
        scanf("%d %d %c\n",&n,&m,&o);
        // printf("::%d %d %c\n",n,m,o);
        printf("%d\n",in[m][o-'a']-in[n-1][o-'a']);
    }
    return 0;
}