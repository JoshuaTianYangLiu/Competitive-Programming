#include <bits/stdc++.h>

using namespace std;
int in[110];
int main() {
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
        sum+=in[i];
    }
    sort(in,in+n);
    int i=0;
    while(round(sum/(double)n)<5){
        sum+=5-in[i++];
    }
    printf("%d\n",i);

    return 0;
}