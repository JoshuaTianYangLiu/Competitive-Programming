#include <bits/stdc++.h>

using namespace std;
char in[3];
char tape[110];
int main() {
    int n;
    scanf("%d",&n);
    int point=0;
    while(n--){
        scanf("%s",in);
        if(in[0]=='h')point=max(0,point-1);
        if(in[0]=='l')point++;
        if(in[0]=='r')tape[point]=in[1];
    }
    for(int i=0; i<110; i++){
        if(tape[i]!=0)printf("%c",tape[i]);
    }
    return 0;
}