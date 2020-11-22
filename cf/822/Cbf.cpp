#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int>> piii;
piii in[200020];
int main() {
    // freopen("data.in","r",stdin);
    int n,x;
    scanf("%d %d",&n,&x);
    for(int i=0; i<n; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        in[i]={a,{b,c}};
    }
    int ans=2e9+100;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            piii a=in[i],b=in[j];
            if(a.second.first<b.first||b.second.first<a.first){
                int lena=a.second.first-a.first+1,lenb=b.second.first-b.first+1;
                if(lena+lenb==x){
                    ans=min(ans,a.second.second+b.second.second);
                }
            }
        }
    }
    printf("%d\n",ans);
    // fclose(stdin);
    return 0;
}