#include <bits/stdc++.h>

using namespace std;
int MM=2e5;
int main() {
    srand(time(NULL));
    freopen("data.in","w",stdout);
    int n=rand()%MM,x=rand()%MM;
    printf("%d %d\n",n,x);
    for(int i=0; i<n; i++){
        int l=rand()%MM,r=l+rand()%x,c=rand();
        printf("%d %d %d\n",l,r,c);
    }
    fclose(stdout);
    return 0;
}