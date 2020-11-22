#include <bits/stdc++.h>

using namespace std;
int in[2000010];
int main() {
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    int up=0;
    if(in[2]>in[1])up=1;
    if(in[1]>in[2])up=2;
    int ans=up?1:0;

    for(int i=3; i<=n; i++){
        if(in[i]>in[i-1]&&up!=1){
            ans++;
            up=1;
        }
        if(in[i]<in[i-1]&&up!=2){
            ans++;
            up=2;
        }
    }
    printf("%d\n",ans+1);
    return 0;
}