#include <bits/stdc++.h>

using namespace std;
vector<pair<int,pair<int,int>>> in;
char ans[1000010];
int main() {
    int t;
    scanf("%d",&t);
    for(int t1=1; t1<=t; t1++){
        memset(ans,0,sizeof(ans));
        deque<pair<int,pair<int,int>>> j,c;
        in.clear();
        printf("Case #%d: ",t1);
        int n;
        scanf("%d",&n);
        for(int i=0,a,b; i<n; i++){
            scanf("%d %d",&a,&b);
            in.push_back({a,{b,i}});
        }
        sort(in.begin(),in.end());
        for(pair<int,pair<int,int>> a:in){
            if(j.empty()||a.first>=j.back().second.first){
                j.push_back(a);
                ans[a.second.second]='J';
            }else if(c.empty()||a.first>=c.back().second.first){
                c.push_back(a);
                ans[a.second.second]='C';
            }else{
                printf("IMPOSSIBLE");
                goto Impossible;
                //Break Out Impossible
            }
        }

        printf("%s",ans);
        Impossible:
        printf("\n");
    }
    return 0;
}