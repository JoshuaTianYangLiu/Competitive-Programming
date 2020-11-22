#include <bits/stdc++.h>

using namespace std;
bool in[1100];
bool chk[1100];
int n;
bool check(int k){
    for(int i=0; i<1024; i++){
        if(in[i]){
            chk[i^k]=true;
        }
    }
    for(int i=0; i<1024; i++){
        if(in[i]!=chk[i])return false;
    }
    return true;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(in,false,sizeof(in));
        scanf("%d",&n);
        for(int i=0,a; i<n; i++){
            scanf("%d",&a);
            in[a]=true;
        }
        // if(n%2==1){
        //     printf("-1\n");
        //     continue;
        // }
        bool ree=false;
        for(int i=1; i<1024; i++){
            memset(chk,false,sizeof(chk));
            if(check(i)){
                printf("%d\n",i);
                ree=true;
                break;
            }
        }
        if(!ree){
            printf("-1\n");
        }
    }
    return 0;
}