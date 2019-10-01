#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
int bit[2011][2011];
void update(int val,int pos,int r){
    for(;pos<2011;pos+=pos&-pos){
        bit[r][pos]+=val;
        bit[r][pos]%=MM;
    }
}
int rsq(int x,int r){
    int n=0;
    for(;x;x-=x&-x){
        n+=bit[r][x];
        n%=MM;
    }
    return n;
}
int rsq(int x,int y,int r){return rsq(y,r)-rsq(x-1,r);}
int main() {
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0,a,b,c,d; i<n; i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        //r c t
        //r c x
        if(a==1){
            update(d,b,b+c);
        }else{
            ans+=rsq(b-d,b,b+c);
            ans%=MM;
        }
    }
    printf("%d\n",ans);
    return 0;
}