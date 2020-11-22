#include <bits/stdc++.h>

using namespace std;
int in[2020];
vector<int> freq[2];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        freq[0].clear();
        freq[1].clear();
        int n;
        scanf("%d",&n);
        for(int i=1; i<=2*n; i++){
            scanf("%d",&in[i]);
            freq[in[i]%2].push_back(i);
            
        }
        if(freq[0].size()%2==0){
            // e e
            if(freq[0].size()!=0){
                for(int i=2; i<freq[0].size(); i+=2){
                    printf("%d %d\n",freq[0][i],freq[0][i+1]);
                }
                for(int i=0; i<freq[1].size(); i+=2){
                    printf("%d %d\n",freq[1][i],freq[1][i+1]);
                }
            }else{
                for(int i=2; i<freq[1].size(); i+=2){
                    printf("%d %d\n",freq[1][i],freq[1][i+1]);
                }
            }
        }else{
            // o o
            if(freq[0].size()==1){
                for(int i=1; i<freq[1].size(); i+=2){
                    printf("%d %d\n",freq[1][i],freq[1][i+1]);
                }
            }else{
                for(int i=1; i<freq[0].size()-1; i+=2){
                    printf("%d %d\n",freq[0][i],freq[0][i+1]);
                }
                for(int i=1; i<freq[1].size()-1; i+=2){
                    printf("%d %d\n",freq[1][i],freq[1][i+1]);
                }
            }
        }
    }
    return 0;
}