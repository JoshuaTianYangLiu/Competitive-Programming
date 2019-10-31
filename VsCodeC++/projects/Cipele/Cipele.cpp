#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[200010];
bool checked[200010];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        in[i]={a,0};
    }
    for(int i=n,a; i<n+m; i++){
        scanf("%d",&a);
        in[i]={a,1};
    }
    sort(begin(in),begin(in)+n+m);
    int find=n<m?1:0;
    int ans=0;
    for(int i=0; i<m+n; i++){
        if(in[i].second==find){
            int l=-1,r=-1;
            for(int j=i; j>=0; j--){
                if(in[j].second!=find&&!checked[l]){
                    l=j;
                    break;
                }
            }
            for(int j=i; j<m+n; j++){
                if(in[j].second!=find&&!checked[r]){
                    r=j;
                    break;
                }
            }
            if(l!=-1&&abs(in[i].first-in[l].first)>ans)ans=abs(in[i].first-in[l].first),checked[l]=true;;
            if(r!=-1&&abs(in[i].first-in[r].first)>ans)ans=abs(in[i].first-in[r].first),checked[r]=true;;
            printf("\t%d %d %d\n",in[l].first,in[r].first,ans);
        }
        printf("%d %d %d\n",in[i].first,in[i].second,find);
    }
    printf("%d",ans);
    return 0;
}
