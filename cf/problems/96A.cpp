#include <bits/stdc++.h>

using namespace std;
char in[110];
int main() {
    scanf("%s",in);
    int n = strlen(in);
    int id=0,cnt=0;
    for(int i=0; i<n; i++){
        if(id==in[i]-'0'){
            cnt++;
        }else{
            id=in[i]-'0';
            cnt=1;
        }
        if(cnt==7){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}