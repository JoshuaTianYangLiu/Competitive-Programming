#include <bits/stdc++.h>

using namespace std;
int in[110];
void check(){
    int n,k,l;
    scanf("%d %d %d",&n,&k,&l);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    for(int i=1; i<=n; i++){
        if(in[i-1]>=l&&in[i]>=l){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    return;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        check();
    }
    return 0;
}