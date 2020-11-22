#include <bits/stdc++.h>

using namespace std;
int in[50];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int os=0,es=0;
        for(int i=0; i<n; i++){
            scanf("%d",&in[i]);
            if(in[i]%2!=i%2){
                if(i%2==0)os++;
                else es++;
            }
        }
        if(os==es)printf("%d\n",os);
        else printf("-1\n");
        // printf("%d %d\n",os,es);

    }
    return 0;
}