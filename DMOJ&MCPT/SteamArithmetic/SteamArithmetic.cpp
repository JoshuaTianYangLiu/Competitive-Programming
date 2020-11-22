#include <bits/stdc++.h>

using namespace std;
char in[1000010];
bool isInt(int l,int r){
    for(;l<=r; l++){
        if(in[l]<'0'||in[l]>'9')return false;
    }
    return true;
}
int toInt(int l,int r){
    int ret=0;
    for(;l<=r;l++){
        ret = 10*ret + in[l]-'0';
    }
    return ret;
}
int solve(int l=0,int r=strlen(in)-1){
    if(isInt(l,r)){
        // printf("%d %d %d\n",l,r,toInt(l,r));
        return toInt(l,r);
    }
    char op = in[l+1];
    int p = l+3;
    int depth=0;
    while(depth!=0||in[p]!=' '){
        if(in[p]=='(')depth++;
        if(in[p]==')')depth--;
        p++;
    }
    // printf("%c %d %d %d \"%c\"\n",op,p,l,r,in[p]);
    if(op=='+')return solve(l+3,p-1)+solve(p+1,r-1);
    if(op=='*')return solve(l+3,p-1)*solve(p+1,r-1);
    if(op=='-')return solve(l+3,p-1)-solve(p+1,r-1);
    if(op=='q')return solve(l+3,p-1)/solve(p+1,r-1);
    if(op=='r')return solve(l+3,p-1)%solve(p+1,r-1);
}
int main() {
    // freopen("data.in","r",stdin);
    int v=10;
    string ree;
    while(v--){
        getline(cin,ree);
        strcpy(in,ree.c_str());
        int reee=strlen(in)-1;
        while(in[reee]==' ')in[reee--]=0;
        // printf("::%s\n",in);
        printf("%d\n",solve(0,reee));
    }
    return 0;
}