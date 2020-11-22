#include <bits/stdc++.h>

using namespace std;

int lsb(int x){
    return x&-x;
}
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    vector<int> ree;
    for(int i=b; i>0; i--){
        if(lsb(i)<=a){
            ree.push_back(i);
            a-=lsb(i);
        }
    }
    if(a!=0){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",ree.size());
    for(int z:ree)
        printf("%d ",z);
    return 0;
}