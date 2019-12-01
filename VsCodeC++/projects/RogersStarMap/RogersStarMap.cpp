#include <bits/stdc++.h>

using namespace std;
int bit[32010];
int level[15000];
void update(int x){
    for(;x<32010;x+=x&-x)bit[x]++;
}
int query(int x){
    int sum=0;
    for(;x;x-=x&-x)sum+=bit[x];
    return sum;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        level[query(++a)]++;
        update(a);
    }
    for(int i=0; i<n; i++){
        printf("%d\n",level[i]);
    }
    return 0;
}