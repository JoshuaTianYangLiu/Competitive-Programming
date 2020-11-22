#include <bits/stdc++.h>
 
using namespace std;
pair<int,int> in[100010];
pair<int,int> toSort[100010];
int ans[100010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(ans,0,sizeof(ans));
        int n;
        scanf("%d",&n);
        for(int i=1,a; i<=n; i++){
            scanf("%d",&a);
            in[i]={a,i};
        }
        sort(begin(in)+1,begin(in)+n+1);
        for(int i=1; i<=n; i++){
            toSort[i]={in[i].second,i};
        }
        sort(begin(toSort)+1,begin(toSort)+n+1);
        // for(int i=1; i<=n; i++)printf("%d ",in[i].first);
        // printf("\n");
        // for(int i=1; i<=n; i++)printf("%d ",in[i].second);
        // printf("\n");
        int finalAns=0;
        for(int i=1; i<=n; i++){
            ans[i]=1;
            for(int j=i; j<i; j+=i){
                int jj=toSort[j].second,ii=toSort[i].second;
                if(in[ii].first>in[jj].first&&in[ii].second%in[jj].second==0)ans[i]=max(ans[i],ans[j]+1);
            }
            finalAns=max(finalAns,ans[i]);
            // printf("::%d\n",ans[i]);
        }
        printf("%d\n",finalAns);
 
    }
    return 0;
}