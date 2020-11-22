#include <bits/stdc++.h>

using namespace std;
char str[100];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0; i<100; i++)str[i]='a';
        int n;
        scanf("%d",&n);
        printf("%s\n",str);
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            if(str[a]=='a')str[a]='b';
            else if(str[a]=='b')str[a]='a';
            printf("%s\n",str);
        }
    }
    return 0;
}