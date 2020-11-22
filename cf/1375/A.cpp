#include <bits/stdc++.h>

using namespace std;
int in[110];
int ree[110];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&in[i]);
        }
        for(int i=1; i<n; i++){
            if(in[i]-in[i+1]>0){
                for(int j=1; j<=i; j++)in[i]=-in[i];
            }else{
                // in[i]=-in[i];
                // in[i+1]=-in[i+1];
            }
        }
        for(int i=1; i<n; i++){
            printf("%d ",in[i+1]-in[i]);
        }
        printf("\n");
    }
    return 0;
}