#include <bits/stdc++.h>

using namespace std;
char in[100010];
int check[100010];
pair<pair<int,int>,int> a[100010];
int main() {
    scanf("%s",&in);
    int n=strlen(in);
    in[n++]='$';
    for(int i=0; i<n; i++)a[i]={{in[i],0},i};
    sort(a,a+n);
    for(int i=1; i<n; i++){
        int b=a[i].second,c=a[i-1].second;
        if(a[i].first==a[i-1].first){
            check[b]=check[c];
        }else{
            check[b]=check[c]+1;
        }
    }
    int k=0;
    while((1<<k)<n){
        for(int i=0; i<n; i++){
            a[i]={{check[i],check[(i+(1<<k))%n]},i};
        }
        sort(a,a+n);
        check[a[0].second]=0;
        for(int i=1; i<n; i++){
            int b=a[i].second,c=a[i-1].second;
            if(a[i].first==a[i-1].first){
                check[b]=check[c];
            }else{
                check[b]=check[c]+1;
            }
        }
        k++;
    }
    for(int i=0; i<n; i++){
        printf("%d ",a[i].second);
    }
    printf("\n");
    return 0;
}