#include <bits/stdc++.h>

using namespace std;
bool hiX[55],hiY[55];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(hiX,false,sizeof(hiX));
        memset(hiY,false,sizeof(hiY));
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int a;
                scanf("%d",&a);
                if(a){
                    hiX[j]=true;
                    hiY[i]=true;
                }
            }
        }
        int cntX=0,cntY=0;
        for(int i=0; i<n; i++){
            if(!hiY[i])cntY++;
        }   
        for(int i=0; i<m; i++){
            if(!hiX[i])cntX++;
        }   
        // printf("%d\n",min(cntX,cntY));
        printf("%s\n",min(cntX,cntY)%2==0?"Vivek":"Ashish");
    }
    return 0;
}