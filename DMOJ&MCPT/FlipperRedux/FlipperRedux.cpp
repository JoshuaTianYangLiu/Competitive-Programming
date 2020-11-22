#include <bits/stdc++.h>

using namespace std;
int in[2020][2020];
queue<pair<int,int>> instruc;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&in[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        if(in[i][1]){
            for(int j=1; j<=n; j++)in[i][j]=1-in[i][j];
            instruc.push({0,i});
        }
    }
    for(int i=1; i<=n; i++){
        if(in[1][i]){
            for(int j=1; j<=n; j++)in[j][i]=1-in[j][i];
            instruc.push({1,i});
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(in[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n",instruc.size());
    while(!instruc.empty()){
        printf("%s %d\n",instruc.front().first?"C":"R",instruc.front().second);
        instruc.pop();
    }
    return 0;
}