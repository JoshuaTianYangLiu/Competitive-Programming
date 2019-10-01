#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,w,h,n;
    scanf("%d %d %d %d %d",&x,&y,&w,&h,&n);
    if((y+h<x/2&&y<x/2)||(y>2*(x+w)&&y>2*x)){
        printf("NO");
        return 0;
    }
    for(int i=max(0,w-5); i<w;i++){
        for(int j=0; j<min(h,4); j++){
            if((x+y+i+j)%3==0&&(x+j+y+i)/3<n){
                printf("YES");
                return 0;
            }
        }
    }
    for(int i=max(0,h-5); i<h;i++){
        for(int j=0; j<min(w,4); j++){
            if((x+y+i+j)%3==0&&(x+j+y+i)/3<n){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
