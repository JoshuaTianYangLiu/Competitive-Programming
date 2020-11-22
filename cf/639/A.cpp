#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n==1||m==1)printf("YES\n");
        else if(n==2&&m<3)printf("YES\n");
        else if(m==2&&n<3)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

/*
1 x n YES
2 x n < 3 YES

*/