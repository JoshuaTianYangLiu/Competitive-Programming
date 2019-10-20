#include <bits/stdc++.h>

using namespace std;

bool arr[5000010];
int main() {
    int w,d,v;
    scanf("%d %d",&w,&d);
    bool in[d];
    stack<pair<int,int>> q;
    for(int i=0,a; i<d; i++){
        scanf("%d",&a);
        in[i]=a;
        q.push({a,0});
        if(w==0)arr[a]=true;
    }
    while(!q.empty()){
        pair<int,int> t=q.top(); q.pop();
        if(t.second==w){
            arr[t.first]=true;
        }
        for(int i:in){
            if(t.second<=w){
                q.push({t.first+i,t.second+1});
                if(t.first*i<5000010)q.push({t.first*i,t.second+1});
            }
        }
    }
    scanf("%d",&v);
    for(int i=0,a; i<v; i++){
        scanf("%d",&a);
        printf("%c\n",arr[a]?'Y':'N');
    }
    return 0;
}