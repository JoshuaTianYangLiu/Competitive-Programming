#include <bits/stdc++.h>

using namespace std;
vector<int> factors;
vector<set<int>> memo;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            factors.push_back(i);
            if(n/i!=i)factors.push_back(n/i);
        }
    }
    int m=factors.size();
    sort(factors.begin(),factors.end());
    memo.resize(factors.size());
    memo[0].insert(0);
    for(int i=0; i<m; i++){
        for(int j=0;j<i; j++){
            if(factors[i]%factors[j]==0){
                for(int a:memo[j]){
                    memo[i].insert(a+factors[i]/factors[j]-1);
                }
            }
        }
    }
    printf("%d\n",memo[m-1].size());
    for(int a:memo[m-1])printf("%d ",a);
    return 0;
}
