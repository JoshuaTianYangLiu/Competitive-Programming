#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char in[10][10];
int pos[] = {0,1,2,3,4,5,6,7};

bool check(){
    for(int i=0; i<8; i++){
        if(in[i][pos[i]]=='*')return false;
    }
    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            if(abs(i-j)==abs(pos[i]-pos[j]))return false;
        }
    }
    return true;
}

int main() {
    for(int i=0; i<8; i++){
        scanf("%s",&in[i]);
    }
    int ans=0;
    do{
        if(check()){
            // for(int i=0; i<8; i++)printf("%d ",pos[i]);
            // printf("\n");
            ans++;
        }
    }while(next_permutation(pos,pos+8));
    printf("%d\n",ans);
    return 0;
}