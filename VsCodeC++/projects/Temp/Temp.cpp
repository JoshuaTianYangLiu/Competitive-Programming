#include <bits/stdc++.h>

using namespace std;
bool in[513];
int main() {
    for(int i=0,a; i<2000; i++){
        scanf("%d",&a);
        in[a]=true;
    }
    for(int i=0; i<=35; i++){
        if(!in[i])printf("a: %d\n",i);
    }
    return 0;
}