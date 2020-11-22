#include <bits/stdc++.h>

using namespace std;
char in[110];
int main() {
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    int cnt=0;
    for(int i=0; i<n; i++){
        scanf("%s",in);
        if(cnt+strlen(in)>k){
            printf("\n%s",in);
            cnt=strlen(in);
        }else{
            if(i==0)printf("%s",in);
            else printf(" %s",in);
            cnt+=strlen(in);
        }
    }

    return 0;
}