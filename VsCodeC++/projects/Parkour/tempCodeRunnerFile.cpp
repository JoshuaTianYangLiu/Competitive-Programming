#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,w,h,n;
    scanf("%d %d %d %d %d",&x,&y,&w,&h,&n);
    for(int i=0; i<min(4,w);i++){
        for(int j=0; j<min(4,h);j++){
            if((x+y+i+j)%3==0&&(x+y+i+j)/3<n){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
