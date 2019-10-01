#include <bits/stdc++.h>

using namespace std;
char a[5001];
int main() {
    scanf("%s",a);
    for(int i=0; i<strlen(a)-1; i++){
        bool b=false;
        for(int j=i+1; j<strlen(a); j++){
            if(a[j]-a[j-1]==1)b=true;
            if(a[i]==a[j]&&b){
                printf("Sushi is Here!\n");
                return 0;
            }
        }
    }
    printf("Better Luck Next Time.\n");
    return 0;
}
