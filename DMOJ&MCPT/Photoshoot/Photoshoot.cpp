#include <bits/stdc++.h>

using namespace std;
int in[1010];
bool check[1010];
int n;
bool c(int pos){
    memset(check,false,sizeof(check));
    check[pos]=true;
    for(int i=0; i<n-1; i++){
        pos=in[i]-pos;
        if(pos<=n&&pos>0&&!check[pos]){
            check[pos]=true;
        }else{
            return false;
        }
    }
    return true;
}
int main() {
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n-1; i++){
        scanf("%d",&in[i]);
    }
    for(int i=1; i<=n; i++){
        if(c(i)){
            printf("%d ",i);
            int rawr=i;
            for(int j=0; j<n-1; j++){
                rawr=in[j]-rawr;
                if(j==n-2)printf("%d",rawr);
                else printf("%d ",rawr);
            }
            return 0;
        }
    }
    return 0;
}