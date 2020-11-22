#include <bits/stdc++.h>

using namespace std;
int in[200010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&in[i]);
        }
        int l=0,r=n-1;
        while(in[l]==l+1)l++;
        while(in[r]==r+1)r--;
        bool over=false;
        bool oop=false;
        for(int i=l; i<=r; i++){
            if(in[i]==i+1)over=true;
            else oop=true;
        }
        if(!oop)printf("0\n");
        else if(over)printf("2\n");
        else printf("1\n");

    }
    return 0;
}