#include <bits/stdc++.h>

using namespace std;
char a[100010],b[100010];
int n;
int tr(int x){

}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",a);
        scanf("%s",b);
        int flips=0;
        for(int i=n-1; i>=0; i--){
            if(b[i]-'0'!=(a[tr(i)]-'0'+flips)%2){
                flips++;
            }
        }
    }
    return 0;
}