#include <bits/stdc++.h>
using namespace std;
#define pi pair<long long,int>
int main() {
    int mic,n,time;
    scanf("%d %d %d",&mic,&n,&time);
    vector<long long> pq;
    priority_queue<pi, vector<pi>, greater<pi>> people;
    for(int i=0; i<mic; i++) pq.push_back(0);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        people.push({a,b});
    }
    while(!people.empty()){
        pi t=people.top(); people.pop();
        int pos=upper_bound(pq.begin(),pq.end(),t.first)-pq.begin();
        pos==0?pos:pos--;
        if(t.first-pq[0]>=time){
            printf("%lld",pq[0]);
            return 0;
        }
        pq[pos]=max(t.first,pq[pos])+t.second;
        sort(pq.begin(),pq.end());
    }
    printf("%lld",pq[0]);
    return 0;
}
