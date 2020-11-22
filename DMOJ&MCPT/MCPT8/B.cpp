#include <bits/stdc++.h>

using namespace std;
char in[1000010];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",in);
    int a=0,b=0,c=0;
    int ans1=0,ans2=0,ans3=0;
    for(int i=0; i<n; i++){
        if(in[i]=='w'){
            if(c>ans3){
                ans1=a;
                ans2=b;
                ans3=c;
            }
            c=0;
            a=0;
            b=0;
        }else{
            if(in[i]=='c')b++;
            else a++;
            c++;
        }
    }
    if(c>ans3){
        ans1=a;
        ans2=b;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}