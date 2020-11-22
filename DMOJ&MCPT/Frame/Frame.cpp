#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m+2; i++)printf("#");
    printf("\n");
    for(int i=0; i<n; i++){
        char a[101];
        scanf("%s",a);
        printf("#%s#\n",a);
    }
    for(int i=0; i<m+2; i++)printf("#");
    return 0;
}