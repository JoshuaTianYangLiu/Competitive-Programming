#include <bits/stdc++.h>

using namespace std;
unordered_map<int,int> um;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        if(um.find(a)==um.end()){
            um.insert({a,1});
            printf("%d ",i);
        }
    }
    return 0;
}