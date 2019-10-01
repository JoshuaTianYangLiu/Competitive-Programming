#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq[4];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        pq[i%4].push(a);
    }
    for(int i=1,a; i<=n; i++){
        printf("%d ",pq[i%4].top()); pq[i%4].pop();
    }
    return 0;
}
