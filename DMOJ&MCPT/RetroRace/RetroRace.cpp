#include <bits/stdc++.h>

using namespace std;
char ree[25];
string in;
map<string,int> m;
queue<string> hi;
int main() {
    int n;
    scanf("%d\n",&n);
    for(int i=0; i<n; i++){
        getline(cin,in);
        // cout << in << '\n';
        m[in]=1;
        hi.push(in);
    }
    while(strcmp(ree,"finished")!=0){
        getline(cin,in);
        // cout << in << '\n';
        strcpy(ree,in.c_str());
        m[in]++;
        n--;
    }
    cout<<n+2<<'\n';
    while(!hi.empty()){
        string a = hi.front(); hi.pop();
        if(m[a]==1)cout<<a<<'\n';
    }
    return 0;
}

//I hate strings