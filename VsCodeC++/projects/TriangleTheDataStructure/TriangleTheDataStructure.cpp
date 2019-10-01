#include <bits/stdc++.h>

using namespace std;
deque<pair<int,int>> dq[3001];
int main() {
    int size,k;
    scanf("%d",&size,&k);
    int ans=0;
    for(int i=1; i<=size; i++){
        for(int j=1,in; j<=i; k++){
            scanf("%d",&in);
            while(!dq[j].empty()&&dq[j].back().first<in)dq[j].pop_back();
            dq[j].push_back({in,i});
            while(!dq[j].empty()&&dq[j].front().second<i-k)dq[j].pop_front();
        }
        deque<pair<int,int>> qd;
        for(int j=1; j<=size&&i>=k; j++){
            while(!qd.empty()&&qd.back().first<dq[j].front().first)qd.pop_back();
            qd.push_back(dq[j].front());
            while(!qd.empty()&&qd.front().second<j-k)qd.pop_front();
            if(j>=k){
                ans+=qd.front().first;
            }

        }
    }

    return 0;
}
