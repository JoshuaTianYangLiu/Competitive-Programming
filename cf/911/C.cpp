#include <bits/stdc++.h>

using namespace std;
int freq[1510];
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    freq[a]++;
    freq[b]++;
    freq[c]++;
    if(freq[1]>0)printf("YES\n");
    else if(freq[2]>1)printf("YES\n");
    else if(freq[3]>2)printf("YES\n");
    else if(freq[4]==2&&freq[2]==1)printf("YES\n");
    else printf("NO\n");
    return 0;
}