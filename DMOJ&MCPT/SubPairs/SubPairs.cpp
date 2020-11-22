#include <bits/stdc++.h>

using namespace std;
vector<int> sets[100010];
int n;
int solve(int x,int y){
    int ret=0;
    for(int i=1; i<=n; i++){
        int found=0;
        int l=0,r=sets[i].size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(sets[i][m]>x)r=m-1;
            else if(sets[i][m]<x)l=m+1;
            else{
                found++;
                break;
            }
        }
        l=0,r=sets[i].size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(sets[i][m]>y)r=m-1;
            else if(sets[i][m]<y)l=m+1;
            else{
                found++;
                break;
            }
        }
        if(found==2)ret++;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=1,a,b,c; i<=n; i++){
        scanf("%d",&a);
        c=a;
        while(a--){
            scanf("%d",&b);
            sets[i].push_back(b);
        }
        sort(begin(sets[i]),begin(sets[i])+c);
    }
    int q;
    scanf("%d",&q);
    int x,y,ans=0;
    while(q--){
        scanf("%d %d",&x,&y);
        // printf("%d %d\n",x,y);
        ans+=solve(x,y);
    }
    printf("%d",ans);
    return 0;
}