#include <bits/stdc++.h>

using namespace std;
int a[1010],b[1010];
int main() {
    int n;
    scanf("%d",&n);
    int tot=0;
    bool isWar=false;
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    for(int i=0; i<n; i++)scanf("%d",&b[i]);
    for(int i=0; i<n; i++){
        if(a[i]==b[i])isWar=true;
        else if(a[i]!=b[i]&&isWar){
            tot++;
            isWar=false;
        }
    }
    if(isWar)tot++;
    printf("%d",tot);
    return 0;
}