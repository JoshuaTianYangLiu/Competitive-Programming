#include <bits/stdc++.h>

using namespace std;
int a[2001][2001];
int main() {
    for(int i = 1; i<2001; i++){
        a[0][i]=1;
    }
    for(int i =2; i<2001; i++){
        for(int j=i;j<2001; j++){
            a[i-1][j]=((a[i-1][j]%1000000007+a[i-2][j]%1000000007)%1000000007+a[i-1][j-1]%1000000007)%1000000007;
        }
    }
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        int c,b;
        scanf("%d-%d",&c,&b);
        printf("Case #%d: %d %d\n",i+1,a[b][c],a[b][b+1]);
    }
}
