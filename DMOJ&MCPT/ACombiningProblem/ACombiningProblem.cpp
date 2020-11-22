#include <bits/stdc++.h>

using namespace std;
int in[100010];
int bit[100010];
void update(int x,int p){for(;x<100010; x+=x&-x)bit[x]+=p;}
int query(int x){int sum=0;for(;x;x-=x&-x)sum+=bit[x];return sum;}
int query(int l,int r){return query(r)-query(l-1);}
vector<int> op[100010];
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
        in[i]+=in[i-1];
    }
    int a,b,c,d;
    while(q--){
        scanf("%d",&a);
        if(a==1){
            scanf("%d %d",&b,&c);
            b%=n;
            if(b==0)b+=n;
            d=n-b+1;
            c%=d;
            if(c==0)c+=d;
            update(query(b-1)+b,c-1);
            op[query(b-1)+b].push_back(c-1);
            //Add something to list
        }
        if(a==2){
            scanf("%d",&b);
            b%=n;
            if(b==0)b+=n;
            b+=query(b-1);
            for(int a:op[b]){
                update(b,-a);
            }
            op[b].clear();
        }
        if(a==3){
            scanf("%d %d",&b,&c);
            b%=n;
            if(b==0)b+=n;
            d=n-b+1;
            c%=d;
            if(c==0)c+=d;
            printf("::%d %d\n",b,c);
            int l=query(b-1)+b,r=query(b+c-1)+b+c-1;
            printf("%d\n",in[r]-in[l-1]);
            // printf("%d %d\n",l,r);
        }
    }
    return 0;
}