#include <bits/stdc++.h>

using namespace std;
char in[100010];
const int MM=1e9+7;
long long fib[100010];
int main() {
    fib[1]=1;
    fib[2]=2;
    for(int i=3; i<100010; i++){
        fib[i]=(fib[i-1]+fib[i-2])%MM;
    }
    scanf("%s",in);
    long long ans=1;
    char cur='s';
    int cnt=0;
    int n=strlen(in);
    for(int i=0; i<n; i++){
        char a=in[i];
        if(a=='m'||a=='w'){
            printf("0\n");
            return 0;
        }
        // printf("::%d %c %c\n",cnt,cur,a);
        if(a=='u'||a=='n'){
            if(a==cur){
                cnt++;
            }else{
                if(cnt){
                    ans*=fib[cnt];
                    ans%=MM;
                }
                cnt=1;
                cur=a;
            }
        }else{
            if(cnt){
                ans*=fib[cnt];
                ans%=MM;
            }
            cur=a;
            cnt=0;
        }
    }
    if(cnt){
        ans*=fib[cnt];
        ans%=MM;
    }
    printf("%lld\n",ans);
    return 0;
}