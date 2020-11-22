#include <bits/stdc++.h>

using namespace std;
int bit[1026][1026];
int l=0;
int lsb(int a){return a&(-a);}
void update(int x,int y1,int a){
    for(;x<=l; x+=lsb(x)){
        for(int y=y1;y<=l; y+=lsb(y)){
            bit[x][y]+=a;
        }
    }
}
int rsq(int x1,int y){
    int n=0;
    for(;y; y-=lsb(y)){
        for(int x=x1;x; x-=lsb(x)){
            n+=bit[x][y];
        }
    }
    return n;
}
int rsq(int a,int b,int c,int d){
    return rsq(c,d)-rsq(c,b-1)-rsq(a-1,d)+rsq(a-1,b-1);
}
//(a,c),(b,d)
int main() {
    int in;
    scanf("%d",&in);
    while(1){
        if(in==0){
            scanf("%d",&l);
            memset(bit,0,sizeof(bit));
        }else if(in==1){
            int x,y,a;
            scanf("%d %d %d",&x,&y,&a);
            x++;y++;
            update(x,y,a);
            // for(int i=1; i<=l; i++){
            //     for(int j=1; j<=l; j++)printf("%d ",bit[i][j]);
            //     printf("\n");
            // }
        }else if(in==2){
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            a++;b++;c++;d++;
            printf("%d\n",rsq(a,b,c,d));
        }else break;
        scanf("%d",&in);
    }
    return 0;
}
