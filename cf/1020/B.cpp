#include <bits/stdc++.h>

using namespace std;
int in[1010];
bool hole[1010];
int solve(int a){
    memset(hole,0,sizeof(hole));
    while(!hole[a]){
        hole[a]=true;
        a=in[a];
    }
    return a;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    for(int i=1; i<=n; i++)printf("%d ",solve(i));
    return 0;
}