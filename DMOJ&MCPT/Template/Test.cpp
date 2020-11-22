#include <bits/stdc++.h>

using namespace std;
void f(vector<int> *b){
    (*b).push_back(1);
}
int main() {
    vector<int> a;
    f(&a);
    printf("%d\n",a.size());
    return 0;
}