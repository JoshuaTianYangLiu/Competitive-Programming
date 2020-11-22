#include <bits/stdc++.h>

using namespace std;
char in[500010];
bool check(char a){
    return a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U';
}
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",in);
    int cnt=0,ans=0;
    bool bol=!check(in[0]);
    for(int i=0; i<n; i++){
        if(cnt>=4){
            ans++;
            cnt=1;
        }
        if(check(in[i])){
            if(bol)cnt++;
            else cnt=1;
            bol=true;
        }else{
            if(!bol)cnt++;
            else cnt=1;
            bol=false;
        }
    }
    if(cnt>=4){
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}