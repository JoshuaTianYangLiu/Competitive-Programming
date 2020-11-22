#include <bits/stdc++.h>

using namespace std;
int in[9];
int main() {
    int e=0;
    for(int i=0; i<9; i++){
        scanf("%d",&in[i]);
        e+=in[i];
    }
    for(int i=1; i<9; i++){
        for(int j=0; j<i; j++){
            if(e-in[i]-in[j]==100){
                for(int k=0; k<9; k++){
                    if(k!=i&&k!=j)printf("%d\n",in[k]);
                }
            }
        }
    }
    return 0;
}