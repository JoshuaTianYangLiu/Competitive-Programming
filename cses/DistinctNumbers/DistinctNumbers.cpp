#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d",&n);
    set<int> s;
    while(n--){
        int a;
        scanf("%d",&a);
        s.insert(a);
    }
    printf("%d\n",s.size());
    return 0;
}