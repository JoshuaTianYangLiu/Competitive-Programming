#include <bits/stdc++.h>

using namespace std;
char in[100010];
int main() {
    int x=0,y=0;
    scanf("%s",in);
    for(char a:in){
        if(a=='U')y++;
        if(a=='D')y--;
        if(a=='L')x--;
        if(a=='R')x++;
    }
    int mm = min(abs(x),abs(y));
    x=abs(x)-mm;
    y=abs(y)-mm;
    int t = x==0?y:x;
    if(t%2==1)printf("-1\n");
    else{
        printf("%d\n",t/2+mm);
    }
    return 0;
}