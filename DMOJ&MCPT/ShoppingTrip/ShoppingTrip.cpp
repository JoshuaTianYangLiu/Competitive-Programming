#include <bits/stdc++.h>

using namespace std;
int in[50010];
bool f(int a,int b){return abs(a)<abs(b);}
int main() {
    int t,n;
    scanf("%d %d",&t,&n);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
    }
    sort(begin(in),begin(in)+n,f);
    int tot=0;
    int pos=0;
    while(t>=abs(pos-in[tot])){
        t-=abs(pos-in[tot]);
        // printf("%d %d\n",abs(pos-in[tot]),t);
        pos = in[tot++];
    }
    printf("%d\n",tot);
    
    return 0;
}