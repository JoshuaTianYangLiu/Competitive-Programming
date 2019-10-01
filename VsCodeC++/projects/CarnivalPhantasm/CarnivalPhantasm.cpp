#include <bits/stdc++.h>

using namespace std;
int bit[1<<17][100];
void update(int pos,int val,int row){
    for(;pos<100003; pos+=pos&-pos)bit[pos][row]+=val;
}
int query(int k,int row){
    int pos=0;
    for(int i=16; i+1; i--){
        if(bit[pos+(1<<i)][row]<1)pos+=1<<i;
    }
    return pos+1;
}
int main() {
    int n,s;
    scanf("%d %d",&n,&s);
    
    return 0;
}
