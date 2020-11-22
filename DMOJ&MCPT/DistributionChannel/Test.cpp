#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int,greater<int>> s;
    s.insert(3);s.insert(3);s.insert(-1);s.insert(0);
    for(int a:s){printf("%d\n",a);}
    return 0;
}