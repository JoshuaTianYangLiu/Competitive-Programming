#include <bits/stdc++.h>

using namespace std;
char a[3][1000010];
int n;
int diff(int b,int c){
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[b][i]!=a[c][i])cnt++;
        // printf("%c %c\n",a[b][i],a[c][i]);
    }
    return cnt;
}
int main() {
    // scanf("%d",&n);
    scanf("%s",&a[0]);
    scanf("%s",&a[1]);
    scanf("%s",&a[2]);
    n=strlen(a[0]);
    if(diff(0,1)<diff(1,2)&&diff(0,2)<diff(1,2)){
        printf("%s\n",a[0]);
    }else if(diff(2,1)<diff(0,2)&&diff(1,0)<diff(0,2)){
        printf("%s\n",a[1]);
    }else if(diff(2,1)<diff(1,0)&&diff(0,2)<diff(1,0)){
        printf("%s\n",a[2]);
    }else{
        printf("Unrelated\n");
    }
    
    return 0;
}