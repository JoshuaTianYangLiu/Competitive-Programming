#include <bits/stdc++.h>
using namespace std;
long long t,p1,p2,p3,p4;
int main() {
    cin>>t;
    for (long long amount=0; amount<t; amount++) {
        cin>>p1>>p2>>p3>>p4;
        cout<<llabs(p3-p1)*llabs(p4-p2)+1<<'\n';
    }
}