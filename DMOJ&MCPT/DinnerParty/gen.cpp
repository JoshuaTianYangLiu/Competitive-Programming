#include <bits/stdc++.h>

using namespace std;
int in[110];
int main() {
    srand(time(NULL));
    int n=rand()%30+10,m=rand()%100+1000;
    for(int i=0; i<m; i++){
        int a=rand()%n;
        in[a]++;
        in[(a+1)%n]++;
    }
    printf("%d\n",n);
    for(int i=0; i<n; i++){
        printf("%d ",in[i]);
    }
    return 0;
}