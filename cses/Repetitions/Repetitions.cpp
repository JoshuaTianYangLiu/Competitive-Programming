#include <bits/stdc++.h>

using namespace std;
char in[1000010];
int main() {
    scanf("%s",in);
    int n=strlen(in);
    int num=1,maxnum=1;
    for(int i=1; i<n; i++){
        if(in[i]==in[i-1]){
            num++;
            maxnum=max(maxnum,num);
        }else num=1;
    }
    printf("%d\n",maxnum);
    return 0;
}