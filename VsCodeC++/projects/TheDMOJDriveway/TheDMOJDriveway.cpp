#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    deque<string> dq;
    for(int i=0; i<n; i++){
        string a,b;
        cin>>a>>b;
        if(b=="in"){
            dq.push_back(a);
        }else{
            if(dq.back()==a)dq.pop_back();
            else if(dq.front()==a&&m){
                dq.pop_front();
                m--;
            }
        }
    }
    while(!dq.empty()){
        cout<<dq.front()<<endl;
        dq.pop_front();
    }
    return 0;
}
