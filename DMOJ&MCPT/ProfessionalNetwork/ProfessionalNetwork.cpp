#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[200020];
priority_queue<int> pq[200020];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        in[i]={a,b};
        pq[a].push(b);
    }
    sort(begin(in),begin(in)+n);
    int cnt=0,ans=0;
    for(int i=0; i<n; i++){
        if(cnt<in[i].first){
            ans+=in[i].second;
        }
        cnt++;
    }
    printf("%d\n",ans); 
    return 0;
}