#include <bits/stdc++.h>

using namespace std;
int in[20];
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    for(int i=0,a,b,c; i<q; i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            in[b]=c;
        }else if(a==2){
            int ans=0;
            for(int j=b; j<c; j++){
                for(int k=j+1; k<=c; k++){
                    ans+=in[j]|in[k];
                }
            }
            printf("%d\n",ans);
        }else if(a==3){
            int ans=0;
            for(int j=b; j<c; j++){
                for(int k=j+1; k<=c; k++){
                    ans+=in[j]&in[k];
                }
            }
            printf("%d\n",ans);
        }else{
            int ans=0;
            for(int j=b; j<c; j++){
                for(int k=j+1; k<=c; k++){
                    ans+=in[j]^in[k];
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}