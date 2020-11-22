#include <bits/stdc++.h>

using namespace std;
int b[110];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        b[a]=i+1;
    }
    for(int i=1; i<=n; i++)printf("%d ",b[i]);
    return 0;
}