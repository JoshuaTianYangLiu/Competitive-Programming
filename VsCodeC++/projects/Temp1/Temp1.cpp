#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("D:\\Contest-Practice\\Contest-Practice\\VsCodeC++\\projects\\Temp\\input1.in","w",stdout);
    printf("1000\n");
    srand(time(0));
    for(int i=0; i<1000; i++){
        printf("%d\n",rand()%3001);
    }
    fclose(stdout);
    return 0;
}
