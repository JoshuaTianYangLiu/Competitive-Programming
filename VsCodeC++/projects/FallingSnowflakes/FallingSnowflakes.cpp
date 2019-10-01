#include <bits/stdc++.h>

using namespace std;
int tree[5003][5003];
struct instruct1{int r,c,t,val;} inst[200008];
bool fi(instruct1 a,instruct1 b){return a.t<b.t;}
struct query{int type,a,b,c,d,t,pos;} q[100004];
bool fq1(query a,query b){return a.t<b.t;}
bool fq2(query a,query b){return a.pos<b.pos;}
void insert(int x,int y1,int val){
    for(;x<5003;x+=x&-x){
        for(int y=y1;y<5003;y+=y&-y)tree[x][y]+=val;
    }
}
int rsq(int x,int y1){
    int n=0;
    for(;x;x-=x&-x){
        for(int y=y1;y;y-=y&-y)n+=tree[x][y];
    }
    return n;
}
int rsq(int a,int b,int c, int d){return rsq(c,d)-rsq(c,b-1)-rsq(a-1,d)+rsq(a-1,b-1);}
int main() {
    int size,n,qu;
    scanf("%d %d %d",&size,&n,&qu);
    for(int i=1,a,b,c,d; i<=2*n; i+=2){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a++;b++;
        inst[i]={a,b,c,1};
        inst[i+1]={a,b,d,-1};
    }
    sort(begin(inst)+1,begin(inst)+1+2*n,fi);
    for(int i=1,a,b,c,d,t; i<=qu; i++){
        char in;
        scanf("%c",&in);
        while(in==' '||in=='\n')scanf("%c",&in);
        if(in=='R'){
            scanf("%d %d %d",&a,&b,&t);
            a++;b++;
            q[i]={1,a,b,0,0,t,i};
        }else if(in=='C'){
            scanf("%d %d %d",&a,&b,&t);
            a++;b++;
            q[i]={2,a,b,0,0,t,i};
        }else{
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&t);
            a++;b++;c++;d++;
            q[i]={3,a,b,c,d,t,i};
        }
    }
    sort(begin(q)+1,begin(q)+1+qu,fq1);
    int pos=1;
    for(int i=1; i<=qu; i++){
        while(pos<=2*n&&inst[pos].t<=q[i].t){
            insert(inst[pos].r,inst[pos].c,inst[pos].val);
            pos++;
        }
        if(q[i].type==1){
            q[i].type=rsq(q[i].a,1,q[i].b,size);
        }else if(q[i].type==2){
            q[i].type=rsq(1,q[i].a,size,q[i].b);
        }else{
            q[i].type=rsq(q[i].a,1,q[i].b,size)+rsq(1,q[i].c,size,q[i].d)-rsq(q[i].a,q[i].c,q[i].b,q[i].d);
        }
    }
    sort(begin(q)+1,begin(q)+1+qu,fq2);
    for(int i=1; i<=qu; i++){
        printf("%d\n",q[i].type);
    }
    return 0;
}
