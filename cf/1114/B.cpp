#include <bits/stdc++.h>

using namespace std;
int in[200020];
int cpy[200020];
map<int,int> freq;
int f(int a,int b){return a>b;}
int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
        cpy[i]=in[i];
    }
    sort(begin(cpy),begin(cpy)+n,f);
    long long ans=0;
    for(int i=0; i<m*k; i++){
        ans+=cpy[i];
        freq[cpy[i]]++;
    }
    printf("%lld\n",ans);
    int cnt=m;
    int cntcnt=k-1;
    for(int i=0; i<n; i++){
        if(freq[in[i]]!=0){
            freq[in[i]]--;
            cnt--;
        }
        if(cnt==0&&cntcnt!=0){
            cnt=m;
            cntcnt--;
            printf("%d ",i+1);
        }
    }

    return 0;
}