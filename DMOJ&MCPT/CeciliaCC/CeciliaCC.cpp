#include <bits/stdc++.h>

using namespace std;
char in[410][410];
char perm[410][410];
int n,m;
bool same(){
    for(int i=0; i<m; i++){
        if(in[0][i]!=in[1][i])return true;
    }
    return false;
}
bool solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(in[i][j]=='?')return true;

        }
    }
    return same();
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)scanf("%s",&in[i]);
    if(n==1){
        printf("YES\n");
        for(int i=0; i<m; i++){
            if(in[0][i]=='?')printf(".");
            else printf("%c",in[0][i]);
        }
        printf("\n");
        return 0;
    }
    if(solve()){
        printf("YES\n");
        for(int j=0; j<m; j++){
            if(in[0][j]=='?'){
                if(in[1][j]=='?')printf(".");
                if(in[1][j]=='.')printf("X");
                if(in[1][j]=='X')printf(".");
            }else{
                printf("%c",in[0][j]);
            }
        }
        printf("\n");
        for(int j=0; j<m; j++){
            if(in[1][j]=='?'){
                if(in[0][j]=='?')printf("X");
                if(in[0][j]=='.')printf("X");
                if(in[0][j]=='X')printf(".");
            }else{
                printf("%c",in[1][j]);
            }
        }
        printf("\n");
    }else{
        printf("NO\n");
    }
    return 0;
}