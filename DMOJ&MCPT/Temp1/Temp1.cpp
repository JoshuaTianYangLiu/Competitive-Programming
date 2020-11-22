#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int h1,m1,h2,m2;
    scanf("%d:%d December 22 2019",&h1,&m1);
    scanf("%d:%d December 22 2019",&h2,&m2);
    int totalTime= 60*h2+m2-60*h1-m1;
    totalTime*=60;
    printf("%.6f\n",(double)totalTime/n);
    return 0;
}