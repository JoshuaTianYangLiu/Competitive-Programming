#include <bits/stdc++.h>

using namespace std;
int in[400005];
struct t{int left,midLeft,midRight,right;} tree[1600020];
void build(int n,int L,int R){
    if(L==R){
        tree[n]={L,L,L,L};
    }else{
        int M=(L+R)/2;
        build(2*n,L,M);
        build(2*n+1,M+1,R);
        tree[n].left=tree[2*n].left;
        int mL=tree[2*n].midRight-tree[2*n].midLeft+1;
        int m=tree[2*n+1].left-tree[2*n].right+1;
        int mR=tree[2*n+1].midLeft-tree[2*n].midRight+1;
        int mmL=M-tree[2*n].right+1;
        int mmR=tree[2*n+1].left-M+2;
        if(in[M]<=in[M+1]){
            if(m>=mR&&m>=mL){
                tree[n].midRight=tree[2*n+1].left;
                tree[n].midLeft=tree[2*n].right;
            }else if(mL>=mR&&mL>=m){
                tree[n].midRight=tree[2*n].midRight;
                tree[n].midLeft=tree[2*n].midLeft;
            }else{
                tree[n].midRight=tree[2*n+1].midLeft;
                tree[n].midLeft=tree[2*n].midRight;
            }
        }else{
            if(mmL>=mR&&mmL>=mL&&mmL>=mmR){
                tree[n].midLeft=tree[2*n].right;
                tree[n].midRight=M;
            }else if(mmR>=mmL&&mmR>=mL&&mmR>=mR){
                tree[n].midLeft=M+1;
                tree[n].midRight=tree[2*n+1].left;
            }else if(mL>=mmR&&mL>=mmL&&mL>=mR){
                tree[n].midRight=tree[2*n].midRight;
                tree[n].midLeft=tree[2*n].midLeft;
            }else{
                tree[n].midRight=tree[2*n+1].midLeft;
                tree[n].midLeft=tree[2*n].midRight;
            }
        }
        tree[n].right=tree[2*n+1].right;
    }
}
void update(int n,int idx,int L,int R){
    if(L==R){
        tree[n]={L,0,0,L};
    }else{
        int M=(L+R)/2;
        if(L<=idx&&idx<=M)update(2*n,idx,L,M);
        else update(2*n+1,idx,M+1,R);
        tree[n].left=tree[2*n].left;
        int mL=tree[2*n].midRight-tree[2*n].midLeft+1;
        int m=tree[2*n+1].left-tree[2*n].right+1;
        int mR=tree[2*n+1].midLeft-tree[2*n].midRight+1;
        int mmL=M-tree[2*n].right+1;
        int mmR=tree[2*n+1].left-M+2;
        if(in[M]<=in[M+1]){
            if(m>=mR&&m>=mL){
                tree[n].midRight=tree[2*n+1].left;
                tree[n].midLeft=tree[2*n].right;
            }else if(mL>=mR&&mL>=m){
                tree[n].midRight=tree[2*n].midRight;
                tree[n].midLeft=tree[2*n].midLeft;
            }else{
                tree[n].midRight=tree[2*n+1].midLeft;
                tree[n].midLeft=tree[2*n].midRight;
            }
        }else{
            if(mmL>=mR&&mmL>=mL&&mmL>=mmR){
                tree[n].midLeft=tree[2*n].right;
                tree[n].midRight=M;
            }else if(mmR>=mmL&&mmR>=mL&&mmR>=mR){
                tree[n].midLeft=M+1;
                tree[n].midRight=tree[2*n+1].left;
            }else if(mL>=mmR&&mL>=mmL&&mL>=mR){
                tree[n].midRight=tree[2*n].midRight;
                tree[n].midLeft=tree[2*n].midLeft;
            }else{
                tree[n].midRight=tree[2*n+1].midLeft;
                tree[n].midLeft=tree[2*n].midRight;
            }
        }
        tree[n].right=tree[2*n+1].right;
    }
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n;i++){
        scanf("%d",&in[i]);
    }
    build(1,1,n);
    {
        int L=tree[1].left;
        int M=tree[1].midRight-tree[1].midLeft+1;
        int R=n-tree[1].right+1;
        printf("%d\n",max(max(L,M),R));
    }
    for(int i=1,a,b; i<=q; i++){
        scanf("%d %d",&a,&b);
        in[a]=b;
        update(1,a,1,n);
        int L=tree[1].left;
        int M=tree[1].midRight-tree[1].midLeft+1;
        int R=n-tree[1].right+1;
        printf("%d\n",max(max(L,M),R));
    }
    return 0;
}
