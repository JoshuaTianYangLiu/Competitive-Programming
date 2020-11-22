#include <bits/stdc++.h>

using namespace std;
int decIn[100010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d",&a);
        decIn[i]=a;
    }
    sort(decIn,decIn+n);
    int ans=0;
    int m=0;
    for(int i=0; i<n; i++){
        while(decIn[m]==decIn[i]&&m<n)m++;
        if(m>=n)break;
        if(decIn[i]<decIn[m++]){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}