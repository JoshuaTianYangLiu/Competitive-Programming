#include <bits/stdc++.h>

using namespace std;
map<int,pair<int,int>> xVal;
void gen(int a,int i=0){
    for(;i<=30; i++){
        // printf("%d %d %d\n",a,b,i);
        if((a&(1<<i))){
            int c = a+(1<<i);
            if(__builtin_popcount(c)+__builtin_popcount(1<<i)==__builtin_popcount(c^(1<<i))){   //Valid
                xVal[c^(1<<i)]={c,1<<i};
                gen(a+(1<<i),i+1);
                printf("%d %d\n",a,1<<i);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,x,y; i<n; i++){
        scanf("%d %d",&x,&y);
        // printf("%d %d\n",x,y);
        int a=abs(x),b=abs(y);
        gen(a);
        // for(pair<int,int> u:xVal){
        //     printf("%d %d\n",u.first,u.second);
        // }
    }
    return 0;
}