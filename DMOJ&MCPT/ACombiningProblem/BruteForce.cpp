#include <bits/stdc++.h>

using namespace std;
int in[100010],bit[100010];
void update(int i,int k){
    for(;i<100010; i+=i&-i)bit[i]+=k;
}
int query(int i){
    int sum=0;
    for(;i;i-=i&-i)sum+=bit[i];
    return sum;
}
int query(int i,int j){return query(j)-query(i-1);}
int M,L;
int transform(int &a){
    a=((a-1)%M)+1;
}
int transform(int &a,int &b){
    b=((b-1)%(M-a+1))+1;
    a=((a-1)%M)+1;
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    M=n;
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    int a,b,c;
    while(q--){
        scanf("%d",&a);
        if(a==1){
            scanf("%d %d",&b,&c);
            transform(b,c);
            update(b+1,c-1);

        }else if(a==2){
            scanf("%d",&b);
        }else if(a==3){
            scanf("%d %d",&b,&c);
        }
    }
    return 0;
}