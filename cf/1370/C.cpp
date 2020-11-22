#include <bits/stdc++.h>

using namespace std;
int factors[2];
vector<int> sieve;
bool pf[40000];
int main() {
    for(int i=2; i<40000; i++){
        if(!pf[i]){
            sieve.push_back(i);
            for(int j=i; j<40000; j+=i){
                pf[j]=true;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        factors[0]=0;
        factors[1]=0;
        int n;
        scanf("%d",&n);
        if(n==1){
            printf("FastestFinger\n");
            continue;
        }
        if(n%2==1||n==2){
            printf("Ashishgup\n");
            continue;
        }
        for(int a:sieve){
            while(true){
                if(n%a==0){
                    factors[a%2]++;
                    n/=a;
                }else break;
            }
        }
        if(n!=1){
            factors[n%2]++;
        }
        // printf("::%d %d\n",factors[0],factors[1]);
        if(factors[1]==0)printf("FastestFinger\n");
        else if(factors[0]==1&&factors[1]==1)printf("FastestFinger\n");
        else if(factors[0]==1)printf("Ashishgup\n");
        else printf("Ashishgup\n");
    }
    return 0;
}