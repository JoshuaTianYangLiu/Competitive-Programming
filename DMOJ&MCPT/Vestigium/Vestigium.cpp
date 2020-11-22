#include <bits/stdc++.h>

using namespace std;
int in[110][110];
set<int> row[110],col[110];
bool r[110],c[110];
int main() {
    int t;
    scanf("%d",&t);
    for(int t1=1; t1<=t; t1++){
        for(int i=1; i<110; i++){
            row[i].clear();
            col[i].clear();
        }
        memset(r,false,sizeof(r));
        memset(c,false,sizeof(c));
        int n;
        int ans1=0,ans2=0,ans3=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            for(int j=1,a; j<=n; j++){
                scanf("%d",&a);
                if(i==j)ans1+=a;
                if(row[i].find(a)!=row[i].end())r[i]=true;
                row[i].insert(a);
                if(col[j].find(a)!=col[j].end())c[j]=true;
                col[j].insert(a);
            }
        }
        for(int i=1; i<=n; i++){
            if(r[i])ans2++;
            if(c[i])ans3++;
        }
        printf("Case #%d: %d %d %d\n",t1,ans1,ans2,ans3);
    }
    return 0;
}