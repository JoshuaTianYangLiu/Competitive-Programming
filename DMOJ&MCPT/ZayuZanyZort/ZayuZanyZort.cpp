#include <bits/stdc++.h>

using namespace std;
int in[210];
int fi(int a,int b){return a<b;}
int fd(int a,int b){return a>b;}
int main() {
    int n,q,a,b,c;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1) sort(begin(in)+b,begin(in)+c+1,fi);
        else sort(begin(in)+b,begin(in)+c+1,fd);
    }
    for(int i=1; i<=n; i++){
        if(i==n)printf("%d\n",in[i]);
        else printf("%d ",in[i]);

    }
    // printf("\n");
    return 0;
}