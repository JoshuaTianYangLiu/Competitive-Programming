#include <bits/stdc++.h>

using namespace std;
int field[1001];
int zPos;
int main() {
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=0; i<n; i++){
        scanf("%d",&field[i]);
    }
    sort(begin(field),begin(field)+n+1);
    zPos=lower_bound(begin(field),begin(field)+n+1,0)-begin(field);
    return 0;
}