#include <bits/stdc++.h>

using namespace std;

int main() {
    int q,l,r;
    scanf("%d %d %d",&q,&l,&r);
    while(q--){
        int a,x;
        scanf("%d %d",&a,&x);
        if(min(a+x,r)!=r){
            printf("-1\n");
            continue;
        }
        int alen=log2(a)+1,xlen=log2(r)+1; 
        int acnt=0,xcnt=0;
        for(int i=0; i<32; i++){
            if(((a>>acnt)&1)==((r>>i)&1))acnt++;
        }
        if(acnt>=alen){
            printf("%d\n",xlen-alen);
        }else{
            printf("-1\n");
        }

    }
    return 0;
}