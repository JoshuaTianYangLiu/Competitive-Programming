#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,d,cnt=0;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=1; i<101; i++){
        if(i*a%b==c){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
