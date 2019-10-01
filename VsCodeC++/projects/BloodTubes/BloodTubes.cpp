#include <bits/stdc++.h>

using namespace std;
#define MM 500001
int t[MM];
void insert(int x){
    for(;x<MM;x+=x&-x)t[x]++;
}
int rsq(int x){
    int n=0;
    for(;x;x-=x&-x)n+=t[x];
    return n;
}
int rsq(int x,int y){return rsq(y)-rsq(x);}
int main() {
    int size;
    scanf("%d",&size);
    deque<int> dq;
    long long tot=0;
    for(int i=0,a; i<size; i++){
        scanf("%d",&a);
        if(dq.empty())dq.push_back(a);
        int l=rsq(a),r=rsq(a,MM);
        if(l<r){
            dq.push_front(a);
            tot+=l;
        }
        else{
            dq.push_back(a);
            tot+=r;
        }
        insert(a);
    }
    printf("%lld",tot);
    return 0;
}
