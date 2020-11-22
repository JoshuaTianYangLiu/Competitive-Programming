#include <bits/stdc++.h>

using namespace std;
short a[10010][10010];
int n,m,t;
int main() {
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0,x,y; i<t; i++){
        scanf("%d %d",&x,&y);
        if(x!=0&&y!=0&&x!=n&&y!=m) a[x][y]=1;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=m; j++){
            if(a[i][j]==1){
                a[i][j]=0;
            }else{
                a[i][j]=a[i+1][j]+1;
            }
        }
        // a[i][m]=0;
    }
    // for(int i=n; i>=0; i--){
    //     for(int j=0; j<=m; j++)printf("%d",a[i][j]);
    //     printf("\n");
    // }
    int finalAns=0;
    for(int i=0; i<n; i++){
        int h=n-i;
        int ans=0;
        stack<pair<int,int>> s;
        pair<int,int> u;
        for(int j=0; j<=m; j++){
            u={j,h};
            while(!s.empty()&&a[i][j]<s.top().second){
                u = s.top(); s.pop();
                // printf("Popped %d %d\n",u.first,u.second);
                ans=max(ans,u.second*(j-u.first));
            }
            if(s.empty()||a[i][j]>s.top().second){
                s.push({u.first,a[i][j]});
            }
            if(s.empty()||h>s.top().second){
                s.push({j,h});
            }
        }
        while(!s.empty()){
            u = s.top(); s.pop();
            ans=max(ans,u.second*(m-u.first));
        }
        finalAns=max(ans,finalAns);
    }
    printf("%d\n",finalAns);
    return 0;
}