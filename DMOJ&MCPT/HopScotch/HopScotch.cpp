#include <bits/stdc++.h>

using namespace std;
int in[200020];
int sq[200020];
int cnt[200020];
int main() {
    int n;
    scanf("%d",&n);
    int nsq=(int)ceil(sqrt(n));
    for(int i=0; i<n; i++)scanf("%d",&in[i]);
    for(int i=nsq-1; i>=0; i--){
        for(int j=min(nsq*(i+1)-1,n-1); j>=nsq*i; j--){
            if(j>=n)continue;
            // printf("%d %d\n",i,j);
            // printf("%d %d %d\n",j,j+in[j],nsq*(i+1));
            if(j+in[j]>=min(nsq*(i+1),n)){
                sq[j]=j+in[j];
                cnt[j]=1;
            }else{
                sq[j]=sq[j+in[j]];
                cnt[j]=cnt[j+in[j]]+1;
            }
        }
    }
    // printf("%d\n",nsq);
    // for(int i=0; i<n; i++){
    //     printf("%d ",cnt[i]);
    // }
    int k;
    scanf("%d",&k);
    while(k--){
        int a;
        scanf("%d",&a);
        if(a==1){
            int x;
            scanf("%d",&x);
            int ans=0;
            while(x<n){
                ans+=cnt[x];
                assert(x<sq[x]);
                x=sq[x];
            }   
            printf("%d\n",ans);
        }else{
            int x,v;
            scanf("%d %d",&x,&v);
            in[x]=v;
            int i=x/nsq;
            for(int j=min(nsq*(i+1)-1,n-1); j>=nsq*i; j--){
                // printf("%d %d\n",i,j);
                // printf("%d %d %d\n",j,j+in[j],nsq*(i+1));
                if(j+in[j]>=min(nsq*(i+1),n)){
                    sq[j]=j+in[j];
                    cnt[j]=1;
                }else{
                    sq[j]=sq[j+in[j]];
                    cnt[j]=cnt[j+in[j]]+1;
                }
            }
        }
    }
    return 0;
}