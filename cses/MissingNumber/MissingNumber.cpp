#include <bits/stdc++.h>

using namespace std;

bool in[200010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        int a;
        scanf("%d",&a);
        in[a]=true;
    }
    for(int i=1; i<=n; i++){
        if(!in[i])printf("%d\n",i);
    }
    return 0;
}