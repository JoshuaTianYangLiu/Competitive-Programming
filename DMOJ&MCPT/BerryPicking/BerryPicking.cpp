#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n,k;
int in[1010];
int in2[1010];
bool f(int a,int b){return a>b;}
int main() {
    freopen("berries.in","r",stdin);
    // freopen("berries.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
    }
    sort(begin(in),begin(in)+n,f);
    int ans1=0;
    for(int i=0; i<n; i++){
        int s=0;
        for(int j=0; j<i; j++){
            s+=in[j]/in[i];
        }
        if(s>=k/2){
            for(int j=0; j<n; j++)in2[j]=in[j]%in[i];
            sort(begin(in2),begin(in2)+n,f);
            int k1=k-s+k/2-1;
            int ans=in[i]*(s-k/2+1);
            for(int j=0; j<s-k/2-1; j++)ans+=in2[j];
            printf("::%d %d %d\n",k1,in[i],ans);
            // printf("%d",ans);
            if(k1>0)ans1=ans;
        }
    }
    printf("%d\n",ans1);
    return 0;
}