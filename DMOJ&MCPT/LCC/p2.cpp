#include <bits/stdc++.h>

using namespace std;
int in[100010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        in[a]++;
    }
    for(int i=0; i<100010; i++){
        for(int j=0; j<in[i]; j++){
            printf("%d\n",i);
        }
    }
    return 0;
}