#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    queue<pair<int,int>> q;
    for(int i=1; i<=2*n+1; i++){
        q.push({i,2});
    }
    for(int i=2; i<=2*n+1; i+=2){
        q.push({i,1});
        q.push({i,3});
    }
    if(n%2==0){
        for(int i=2; i<=2*n+1; i+=4){
            q.push({i,4});
            q.push({i+1,4});
            q.push({i+2,4});
        }
        for(int i=4; i+4<=2*n+1; i+=4){
            q.push({i,0});
            q.push({i+1,0});
            q.push({i+2,0});
        }
        q.push({2*n+2,2});
        q.push({2*n+2,1});
        q.push({2*n+2,0});
        q.push({2*n+1,0});
        q.push({2*n,0});
        q.push({2,0});
        q.push({1,0});
        q.push({0,0});
        q.push({0,1});
        q.push({0,2});
    }else{
        for(int i=2; i+4<=2*n+1; i+=4){
            q.push({i,4});
            q.push({i+1,4});
            q.push({i+2,4});
        }
        for(int i=4; i<=2*n+1; i+=4){
            q.push({i,0});
            q.push({i+1,0});
            q.push({i+2,0});
        }
        q.push({2,0});
        q.push({1,0});
        q.push({0,0});
        q.push({0,1});
        q.push({0,2});
        q.push({2*n,4});
        q.push({2*n+1,4});
        q.push({2*n+2,4});
        q.push({2*n+2,3});
        q.push({2*n+2,2});
    }
    printf("%d\n",q.size());
    while(q.size()){
        pair<int,int> g=q.front();q.pop();
        printf("%d %d\n",g.first,g.second);
    }
    return 0;
}