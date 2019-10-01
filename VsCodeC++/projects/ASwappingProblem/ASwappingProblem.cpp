#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,greater<int>> pq[4];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        pq[i%3].push(a);
    }
    for(int i=1,a; i<=n; i++){
        printf("%d ",pq[i%3].top()); pq[i%3].pop();
    }
    return 0;
}
