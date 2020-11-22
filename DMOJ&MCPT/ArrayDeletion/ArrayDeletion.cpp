#include <bits/stdc++.h>

using namespace std;
int in[1000010],in2[1000010];
unordered_map<int,int> um;
int bit[1000010];
void update(int pos,int val){
    for(;pos<1000010; pos+=pos&-pos)bit[pos]+=val;
}
int query(int x){
    int n=0;
    for(;x;x-=x&-x)n+=bit[x];
    return n;
}
int query(int x,int y){return query(y)-query(x-1);}
priority_queue<int,vector<int>,greater<int>> out;
/*
10 3
2 1 1
Fails test case
*/
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1,a; i<=m; i++){
        scanf("%d",&a);
        in[i]=a;
        in2[i]=a;
    }
    sort(begin(in)+1,begin(in)+1+m);
    int cnt=1;
    for(int i=1; i<=m; i++){
        if(um.find(in[i])==um.end())um[in[i]]=cnt++;
    }
    memset(in,0,sizeof(in));
    for(int i=1; i<=m; i++){
        int t=query(um[in2[i]])+in2[i];
        printf("%d %d\n",t,um[in2[i]]);
        if(t>n){
            printf("Out of bounds");
            return 0;
        }
        out.push(t);
        update(um[in2[i]],1);
        in[um[in2[i]]]++;
    }
    while(!out.empty()){
        printf("%d ",out.top()); out.pop();
    }
    return 0;
}
