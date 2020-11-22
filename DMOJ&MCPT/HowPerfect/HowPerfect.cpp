#include <bits/stdc++.h>

using namespace std;
int arr[1001];
int main() {
    for(int i=0; i<=10; i++){
        arr[i*i]++;
        arr[i*i*i]+=2;
    }
    int a;
    scanf("%d",&a);
    if(arr[a]==0)printf("Not Perfect At All\n");
    else if(arr[a]==1)printf("Somewhat Perfect\n");
    else if(arr[a]==2)printf("Kinda Perfect\n");
    else if(arr[a]==3)printf("Perfectly Perfect\n");
    return 0;
}