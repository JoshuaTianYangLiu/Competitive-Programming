#include <bits/stdc++.h>

using namespace std;
char in[100010];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",in);
    deque<char> dq;
    dq.push_back(in[0]);
    for(int i=1; i<n; i++){
        if(in[i]<=dq.front())dq.push_front(in[i]);
        else dq.push_back(in[i]);
    }
    while(n--){
        printf("%c",dq.front());
        dq.pop_front();
    }
    return 0;
}