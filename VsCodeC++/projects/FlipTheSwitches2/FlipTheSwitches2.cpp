#include <bits/stdc++.h>

using namespace std;
char in[1010];
bool out[1010];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",in);
    bool firstNum=true;
    for(int i=0; i<n-1;i++){
        if(in[i+1]=='1')out[i]=true;
    }
    for(int i=0; i<n; i++){
        if(in[i]=='1')out[i]=!out[i];
        printf("%d",out[i]?1:0);
    }
    return 0;
}