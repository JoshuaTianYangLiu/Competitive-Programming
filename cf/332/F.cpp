#include <bits/stdc++.h>

using namespace std;
char in[2010];
int main() {
    int n;
    scanf("%d\n%s",&n,in);
    int m = strlen(in);
    int ans=0;
    for(int i=n; i<m; i+=n){
        if(in[i-1]==in[i-2]&&in[i-1]==in[i-3])ans++;
    }
    printf("%d\n",ans);
    return 0;
}