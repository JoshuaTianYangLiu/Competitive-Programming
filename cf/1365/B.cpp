#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[510];
int preIn[510];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            in[i].first=a;
        }
        int cntO=0,cntZ=0;
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            in[i].second=a;
            preIn[i]=a;
            if(a)cntO++;
            else cntZ++;
        }
        if(cntO>0&&cntZ>0){
            printf("Yes\n");
        }else{
            bool ree=false;
            for(int i=1; i<n; i++){
                if(in[i-1].first>in[i].first){
                    printf("No\n");
                    ree=true;
                    break;
                }
            }
            if(!ree){
                printf("Yes\n");
            }
        }
    }
    return 0;
}