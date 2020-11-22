#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        in[i]={a,b};
    }
    sort(begin(in),begin(in)+n);
    double ans=0;
    for(int i=1; i<n; i++){
        ans=max(ans,abs((in[i].second-in[i-1].second)/(double)(in[i].first-in[i-1].first)));
    }
    printf("%.7f\n",ans);
    return 0;
}