#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("data.in","w",stdout);
    srand(time(NULL));
    int n=rand()%10+10,k=rand()%10+30;
    printf("%d %d\n",n,k);
    while(n--){
        printf("%d %d\n",rand()%10+1,rand()%10+1);
    }
    while(k--){
        printf("%d\n",rand()%15+1);
    }
    fclose(stdout);
    return 0;
}