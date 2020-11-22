#include <bits/stdc++.h>

using namespace std;
int in[10];
int main() {
    for(int i=1; i<=999; i++){
        int a=i;
        while(a){
            in[a%10]++;
            a/=10;
        }
        printf("%d: ",i);
        // for(int j=0; j<10; j++)printf("%d ",in[j]);
        printf("%d ",in[1]);
        printf("\n");
    }
    return 0;
}
