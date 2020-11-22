#include <bits/stdc++.h>

using namespace std;
map<string,vector<pair<int,int>>> ma;
char in[1000];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        ma.clear();
        int n,m,p,q;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&m);
            for(int j=0; j<m; j++){
                scanf("%s %d %d\n",in,&p,&q);
                // printf("::%s::\n",in);
                ma[in].push_back({p,q});
            }
        }
        int ans=0;
        int k;
        scanf("%d",&k);
        for(int i=0; i<k; i++){
            scanf("%s %d",in,&p);
            vector<pair<int,int>> hi=ma[in];
            sort(begin(hi),end(hi));
            for(int i=0; i<hi.size(); i++){
                if(hi[i].second<=p){
                    ans+=hi[i].first*hi[i].second;
                    p-=hi[i].second;
                }else{
                    ans+=hi[i].first*p;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}