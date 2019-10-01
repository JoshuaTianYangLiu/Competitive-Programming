#include <bits/stdc++.h>

using namespace std;
unordered_map<int,int> m;
int before[100001];
pair<int,int> after[100001];
int lsBit(int x){return x&(-x);}
void insert(int x){
    for(;x<1e9+12;x+=lsBit(x))m[x]++;
}
int rsq(int x){
    int n=0;
    for(;x;x-=lsBit(x))n+=m[x];
    return n;
}
int rsq(int x,int y){return rsq(y)-rsq(x);}
int main(){
    int size;
    scanf("%d",&size);
    long long tot=0;
    for(int i=1,a; i<=size; i++){
        scanf("%d",&a);
        after[i]={a,i};
    }
    sort(begin(after)+1,begin(after)+size+1);
    for(int i=1; i<=size; i++){
        before[after[i].second]=i;
    }
    for(int i=1; i<=size; i++){
        tot+=rsq(before[i]+1,1e9+11)+1;
        insert(before[i]+1);
    }
    printf("%.2f",tot*1.0/size);
    return 0;
}