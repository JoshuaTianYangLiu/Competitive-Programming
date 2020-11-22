#include <bits/stdc++.h>

using namespace std;
char in[110];
char ans[110];
bool ree[110];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(in,0,sizeof(in));
        int n,a,b,c;
        scanf("%d %d %d %d",&n,&a,&b,&c);
        scanf("%s",in);
        int m=strlen(in);
        for(int i=0; i<m; i++){
            if(in[i]=='R')ans[i]='P';
            if(in[i]=='P')ans[i]='S';
            if(in[i]=='S')ans[i]='R';
        }
        int aans=0;
        for(int i=0; i<m; i++){
            ree[i]=false;
            if(ans[i]=='R'&&a){
                a--;
                aans++;
                ree[i]=true;
            }
            if(ans[i]=='P'&&b){
                b--;
                aans++;
                ree[i]=true;
            }
            if(ans[i]=='S'&&c){
                c--;
                aans++;
                ree[i]=true;
            }
        }
        if(aans>=(n+1)/2){
            printf("YES\n");
            for(int i=0; i<m; i++){
                if(ree[i])printf("%c",ans[i]);
                else{
                    if(a){
                        printf("R");
                        a--;
                    }
                    else if(b){
                        printf("P");
                        b--;
                    }
                    else if(c){
                        printf("S");
                        c--;
                    }
                }
            }
            printf("\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}