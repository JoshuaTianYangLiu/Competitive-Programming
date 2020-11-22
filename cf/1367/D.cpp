#include <bits/stdc++.h>

using namespace std;
char in[55];
int b[55];
char ans[55];
int n,m;
bool empty(){
    for(int i=1; i<=m; i++){
        if(ans[i]==0)return true;
    }
    return false;
}
void magic(){
    vector<int> zz;
    for(int i=1; i<=m; i++){
        if(b[i]==0){
            zz.push_back(i);
            b[i]=-1;
        }
    }
    for(int i=1; i<=m; i++){
        for(int z:zz)b[i]-=abs(i-z);
    }
    int cnt=0;
    int let=0;
    for(int i=n ;i>0; i--){
        if(in[i]==in[let]){
            cnt++;
        }else{
            cnt=1;
            let=i;
        }
        if(cnt==zz.size()){
            for(int j=i; j>0; j--){
                if(in[j]!=in[let]){
                    n=j;
                    break;
                }
            }
            break;
        }
    }
    for(int z:zz)ans[z]=in[let];
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(ans,0,sizeof(ans));
        memset(b,0,sizeof(b));
        scanf("%s",in+1);
        n=strlen(in+1);
        int N=n;
        sort(in+1,in+1+n);
        scanf("%d",&m);
        stack<char> s;
        for(int i=1; i<=m; i++)scanf("%d",&b[i]);
        while(empty()){
            magic();
            // for(int i=1; i<=m; i++)printf("%d ",ans[i]);
            // printf("\n%d\n",m);
        }
        for(int i=1; i<=m; i++)printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}