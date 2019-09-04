#include <bits/stdc++.h>

using namespace std;
bool g[10000001];
int main() {
    memset(g,false,sizeof(g));
    set<int> s;
    int n,m;
    scanf("%d %d",&n,&m);
    s.insert(m);
    for(int i=1,a; i<n; i++){
        scanf("%d",&a);
        auto pos= s.upper_bound(a);
        if(pos!=s.begin())pos--;
        if(*pos>=a){
            printf("NO\n");
            return 0;
        }
        printf("%d %d %d\n",*pos,g[*pos],a);
        if(g[*pos]){
            s.erase(*pos);
        }
        g[*pos]=true;
        s.insert(a);
    }
    printf("YES\n");
    return 0;
}