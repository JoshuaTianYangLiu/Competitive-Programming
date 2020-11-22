#include <bits/stdc++.h>

using namespace std;
long long in[(1<<23)+2];
int g[(1<<23)+2];

int main() {
    int n,j;
    scanf("%d %d",&n,&j);
    deque<long long> dq;
    in[0]=0;
    in[n+1]=0;
    dq.push_back(0);
    for(int r=1; r<=n+1; r++){
        if(r!=n+1)scanf("%lld",&in[r]);
        int t=in[r];
        while(r-dq.front()>j){  //This line cause me so much pain
            dq.pop_front();
        }
        if(!dq.empty()){
            in[r]+=in[dq.front()];
            g[r]=dq.front();
        }
        while(!dq.empty()&&in[dq.back()]>=in[r]){
            dq.pop_back();
        }
        dq.push_back(r);
        // printf("%d %lld %d\n",r,in[r],g[r]);
    }
    printf("%lld\n",in[dq.front()]);

    int a=g[n+1];
    stack<int> s;
    while(a){
        s.push(a);
        a=g[a];
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}
