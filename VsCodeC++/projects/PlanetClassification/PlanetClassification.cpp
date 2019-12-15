#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> um;
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        printf("%d\n",um[a]);
        um[a]++;
    }
    printf("%d\n",um.size());
    return 0;
}