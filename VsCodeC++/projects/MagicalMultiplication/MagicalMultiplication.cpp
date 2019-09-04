#include <bits/stdc++.h>

using namespace std;

int main() {
    char c=getchar();
    int a=0,ans=0;
    while(c!=' '){
        a+=c-'0';
        c=getchar();
    }
    c=getchar();
    while(c!='\n'){
        ans+=a*(c-'0');
        c=getchar();
    }
    printf("%d",ans);
    return 0;
}
