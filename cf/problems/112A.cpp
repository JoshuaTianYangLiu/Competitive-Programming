#include <bits/stdc++.h>

using namespace std;
char tolower(char a){
    if(a>='A'&&a<='Z')return a-'A'+'a';
    return a;
}
char ina[110],inb[110];
int cmp(){
    int n=strlen(ina);
    for(int i=0; i<n; i++){
        if(tolower(ina[i])<tolower(inb[i]))return -1;
        if(tolower(ina[i])>tolower(inb[i]))return 1;
    }
    return 0;
}
int main() {
    scanf("%s\n%s",ina,inb);
    printf("%d\n",cmp());
    return 0;
}