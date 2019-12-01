#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[1011];
pair<int,int> hTime[10100];
bool inToTime[1011];
int check(int i,int j){
    if(in[i].second==in[j].second)return -1;
    if((in[i].first-in[j].first)%(in[i].second-in[j].second)!=0)return -1;
    if((in[i].first-in[j].first)/(in[i].second-in[j].second)<0)return -1;
    return (in[i].first-in[j].first)/(in[i].second-in[j].second);
}
int ree(int n){
    return (1+sqrt(1+8*n))/2;
}
int main() {
    memset(inToTime,false,sizeof(inToTime));
    int n;
    scanf("%d",&n);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        in[i]={a,b};
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x=check(i,j);
            if(x<0)check(j,i);
            if(x!=-1){
                hTime[x].first++;
                // printf("%d",hTime[x].second);
                if(!hTime[x].second)hTime[x].second=in[i].first+in[i].second*x;
                else hTime[x].second=min(in[i].first+in[i].second*x,hTime[x].second);
                // printf("%d\n",x);
            }
            printf("%d\n",x);
        }
    }
    int h=0,t=0,d=0;
    for(int i=0; i<10100; i++){
        if(hTime[i].first>h){
            h=ree(hTime[i].first);
            t=i;
            d=hTime[i].second;
        }
    }
    printf("%d %d %d\n",h,t,d);
    return 0;
}
