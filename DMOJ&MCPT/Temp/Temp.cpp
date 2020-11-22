#include <bits/stdc++.h>

using namespace std;
int main() {
    for(int i=0;;i++){
        int b = i<<3;
        int c = i^525024598;
        if((b^c)==-889275714){
            printf("%d %d %d %d\n",i,b,c,b^c);
            break;
        }
    }
    return 0;
}