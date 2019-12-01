#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[200020];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1,a,b; i<=n; i++){
        scanf("%d %d",&a,&b);
        in[i]={a,b};
        in[i+n]={a,b};
    }
    for(int i=1; i<=n; i++){
        int sum=0;
        for(int j=i; j<=i+n; j++){
            sum+=in[j].second-in[j].first;
            if(sum<0)break;
        }
        if(sum>=0){
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
