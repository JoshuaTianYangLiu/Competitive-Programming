#include <bits/stdc++.h>

using namespace std;
int in[110];
int check[110];
char t[110];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
    }
    scanf("%s",t);
    int m;
    scanf("%d",&m);
    for(int i=0,a,b; i<m; i++){
        scanf("%d %d",&a,&b);
        check[a]++;
        check[b]++;
    }
    for(int i=0; i<n; i++){
        if(in[i]!=check[i]){
            printf("WA\n");
            return 0;
        }
    }
    printf("AC\n");
    return 0;
}