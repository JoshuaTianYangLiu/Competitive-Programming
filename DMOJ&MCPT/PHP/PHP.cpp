#include <bits/stdc++.h>

using namespace std;
int pointingTo[5010];

int main() {
    memset(pointingTo,-1,sizeof(pointingTo));
    scanf("%d",&n);
    for(int i=1,a; i<=n; i++){
        //Check if any are going into i
        //If not i is not apart of loop
        for(int j=1; j<=n; j++){
            if(j!=i&&pointingTo[j]!=0){
                printf("? %d %d\n",j,i);
                scanf("%d",&a);
                if(a){
                    if(pointingTo[i]==-1)pointingTo[i]=1;
                    else pointingTo[i]++;
                }
            }
        }
        if(pointingTo[i]==-1)pointingTo[i]=0;
    }
    return 0;
}