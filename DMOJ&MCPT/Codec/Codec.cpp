#include <bits/stdc++.h>

using namespace std;
string in;
set<char> ss;
int main() {
    for(int i=1; i<=10; i++){
        ifstream file("codec"+to_string(i));
        while(getline(file,in)){
            for(char a:in){
                ss.insert(a);
            }
        }
        file.close();
    }
    for(char b:ss){
        printf("%d\n",b);
    }
    return 0;
}