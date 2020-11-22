#include <bits/stdc++.h>

using namespace std;

pair<int,int> arr[200020];
int ans[200020];
// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
priority_queue<pair<int,int>> pq;
int point(int l,int r){return (l+r)/2;}

int main() {
    freopen("D.out","w",stdout);
    freopen("D.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(arr,0,sizeof(arr));
        memset(ans,0,sizeof(ans));
        int n;
        scanf("%d",&n);
        int m = point(1,n);
        arr[m]={1,n};
        int cnt=1;
        // Len idx
        pq.push({n,n-m});
        // pq.push({n,m});
        while(!pq.empty()){
            pair<int,int> p = pq.top(); pq.pop();
            p.second=n-p.second;
            ans[p.second]=cnt;
            // printf("::%d %d %d\n",p.second,cnt,ans[p.second]);
            // for(int i=1; i<=n; i++){
            //     printf("%d ",ans[i]);
            // }
            // printf("\n");
            cnt++;
            pair<int,int> bound = arr[p.second];
            // printf("::%d %d %d %d %d\n",p.first,p.second,bound.first,bound.second,cnt);
            int mid=point(bound.first,p.second-1);
            if(bound.first<=p.second-1){
                arr[mid]={bound.first,p.second-1};
                pq.push({p.second-1-bound.first+1,n-mid});
            }
            mid=point(p.second+1,bound.second);
            if(p.second+1<=bound.second){
                arr[mid]={p.second+1,bound.second};
                pq.push({bound.second-p.second,n-mid});
            }
        }
        for(int i=1; i<=n; i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}