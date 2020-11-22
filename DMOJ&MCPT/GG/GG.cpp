#include <bits/stdc++.h>

using namespace std;
int tree[100003];
void update(int pos){for(;pos<100003;pos+=pos&-pos)tree[pos]++;}
int rsq(int x){
    int n=0;
    for(;x;x-=x&-x)n+=tree[x];
    return n;
}
int rsq(int a,int b){return rsq(b)-rsq(a-1);}
int main() {
    char a;
    scanf("%c",&a);
    int pos=1;
    while(a!='\n'){
        if(a=='G')update(pos);
        pos++;
        scanf("%c",&a);
    }
    int n;
    scanf("%d",&n);
    for(int i=0,c,b; i<n; i++){
        scanf("%d %d",&c,&b);
        printf("%d\n",rsq(c+1,b+1));
    }
    return 0;
}
