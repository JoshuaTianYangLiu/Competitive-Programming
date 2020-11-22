#include <bits/stdc++.h>

using namespace std;

pair<int,int> shoes[200010];
int people[200010];
int anspre[200010],anssuf[200010];

bool f(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n+1; i++){
        scanf("%d",&shoes[i].first);
        shoes[i].second=i;
    }
    for(int i=1; i<=n; i++)scanf("%d",&people[i]);
    sort(shoes+1,shoes+2+n);
    sort(people+1,people+n+1);

    for(int i=1; i<=n; i++){
        anspre[i] = max(anspre[i-1],max(shoes[i].first-people[i],0));
    }
    for(int i=n+1; i>1; i--){
        anssuf[i] = max(anssuf[i+1],max(shoes[i].first-people[i-1],0));
    }
    for(int i=1; i<=n+1; i++){
        shoes[i].first=max(anspre[i-1],anssuf[i+1]);
        // printf("%d ",shoes[i].first);
    }
    // printf("\n");
    sort(shoes+1,shoes+n+2,f);
    for(int i=1; i<=n+1; i++){
        printf("%d ",shoes[i].first);
    }

    return 0;
}
