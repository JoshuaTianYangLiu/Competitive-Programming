#include <bits/stdc++.h>

using namespace std;
int in[200010];
int chk[200010];
int t,n;
int solve(){
    for(int i=0; i<n; i++){
        // printf("%d ",in[i]);
        if(chk[(in[i]+i)%n]!=t){
            chk[(in[i]+i)%n]=t;
        }else{
            return false;
        }
    }
    return true;
}
int main() {
    scanf("%d",&t);
    memset(chk,-1,sizeof(chk));
    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&in[i]);
            in[i]=(n+(in[i])%n)%n;
        }
        if(solve())printf("YES\n");
        else printf("NO\n");
        // printf("\n");
        // for(int i=0; i<n; i++){
        //     printf("%d ",(in[i]+i)%n);
        // }
        // printf("\n");
    }
    return 0;
}