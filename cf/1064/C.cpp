#include <bits/stdc++.h>

using namespace std;
char in[100010];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",in);
    sort(in,in+n);
    printf("%s\n",in);
    return 0;
}