#include <bits/stdc++.h>

using namespace std;
struct qu{int t,a,b;};
queue<qu> q;
unordered_map<int,int> scoreToRank;
int rankToId[1000010],idToRank[1000010];
pair<int,int> rankList[1000010];
long long bit[1<<20];
void update(long long val,int x){
    for(;x<(1<<20)+2;x+=x&-x)bit[x]+=val;
}
bool f(pair<int,int> a,pair<int,int> b){return a.first>b.first;}
int query(int v){
    long long sum=0,pos=0;
    for(int i=19; i>=0; i--){
        if(pos+(1<<i)<(1<<20)&&sum+bit[pos+(1<<i)]<v){
            sum+=bit[pos+(1<<i)];
            pos+=1<<i;
        }
    }
    return pos+1;
}
int main() {
    int size;
    int cnt=0;
    scanf("%d",&size);
    for(int i=0,b,c; i<size; i++){
        char a;
        scanf("%c",&a);
        while(a==' '||a=='\n')scanf("%c",&a);
        if(a=='N'){
            scanf("%d %d",&b,&c);
            q.push({1,b,c});
            rankList[cnt++]={c,b};
        }
        if(a=='M'){
            scanf("%d %d",&b,&c);
            q.push({2,b,c});
            rankList[cnt++]={c,b};
        }
        if(a=='Q'){
            scanf("%d",&b);
            q.push({3,b,0});
        }
    }
    sort(begin(rankList),begin(rankList)+cnt,f);
    for(int i=1; i<=cnt; i++){
        scoreToRank[rankList[i-1].first]=i;
        rankToId[i]=rankList[i-1].second;
        // idToRank[rankList[i-1].second]=i;
    }
    for(int i=0; i<size; i++){
        qu t=q.front(); q.pop();
        if(t.t==1){
            update(1,scoreToRank[t.b]);
            idToRank[t.a]=scoreToRank[t.b];
        }else if(t.t==2){
            update(-1,idToRank[t.a]);
            update(1,scoreToRank[t.b]);
            idToRank[t.a]=scoreToRank[t.b];
        }else{
            int n=query(t.a);
            printf("%d\n",rankToId[n]);
        }
    }

    return 0;
}
