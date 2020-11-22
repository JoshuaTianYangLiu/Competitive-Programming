#include <bits/stdc++.h>

using namespace std;
char in[20];
int main() {
    scanf("%s",in);
    int n=strlen(in);
    int ree=0;
    for(int i=0; i<n; i++){
        char a = in[i];
        if(a=='4'||a=='7'){
            ree++;
            // return 0;
        }
    }
    printf("%s\n",ree==4||ree==7?"YES":"NO");
    return 0;
}