#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int cnt=1;
        vector<int> out;
        while(n!=0){
            if(n%10!=0){
                out.push_back((n%10)*cnt);
            }
            cnt*=10;
            n/=10;
        }
        printf("%d\n",out.size());
        for(int a:out){
            printf("%d ",a);
        }
        printf("\n");
    }
    return 0;
}