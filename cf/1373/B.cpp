
#include <bits/stdc++.h>

using namespace std;
char in[110];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(in,0,sizeof(in));
        scanf("%s",in);
        int n=strlen(in);
        int o=0,z=0;
        for(int i=0; i<n; i++){
            if(in[i]=='1')o++;
            else z++;
        }
        printf("%s\n",min(o,z)%2?"DA":"NET");
    }
    return 0;
}