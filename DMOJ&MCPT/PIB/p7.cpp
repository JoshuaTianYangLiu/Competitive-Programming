#include <bits/stdc++.h>

using namespace std;

bool isPrime[50010];
vector<int> pfac[50010];
void genPrimes(){
    for(int i=2; i<50010; i++){
        if(isPrime[i]){
            int j=2;
            while(i*j<50010){
                isPrime[i*j]=false;
                pfac[i*j].push_back(i);
                j++;
            }
        }
    }
}
int in[50010];
pair<int,int> sorted[50010];
set<int> hiImhere;
int main() {
    memset(isPrime,true,sizeof(isPrime));
    genPrimes();
    int totalPrimes = 0;
    int totalIndex = 0;
    int i=2;
    int tot=1;
    while(totalIndex<500){
        tot=1;
        for(;; i++){
            if(isPrime[i]){
                if(tot*i>50000)break;
                tot*=i;
                totalPrimes++;
            }
        }
        printf("%d ",tot);
        totalIndex++;
    }
    printf("\n%d %d\n",totalPrimes,totalIndex);

    // int n;
    // scanf("%d",&n);
    // for(int i=1; i<=n; i++){
    //     scanf("%d",&in[i]);
    //     sorted[i]={in[i],i};
    // }
    // sort(begin(sorted)+1,begin(sorted)+1+n);
    // int minVal=0;
    // for(int i=1; i<=n; i++){
    //     if(sorted[i].second>2&&(!minVal||sorted[i].first==minVal)){
    //         if(minVal==0)minVal=sorted[i].first;
    //         for(int a: pfac[sorted[i].second]){
    //             hiImhere.insert(a);
    //         }
    //     }
    // }
    // for(int a:hiImhere){
    //     //For each case sort as said and find best array
    //     //Perhaps the fac there arent that many primes make it fast enough
    // }
    return 0;
}