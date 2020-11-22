#include <bits/stdc++.h>

using namespace std;
const int MM=1e9+7;
string ree=" ";
int main() {
    // FILE* fi = fopen("ffc3.out","w");
    // FILE* fi = fopen("ff3.out","r");
    // while(1){
    //     auto c = fgetc(fi);
    //     printf("%lld\n",(long long)c);
    //     if(c==EOF)break;
    //     ree+=c;
    // }
    long long f=1;
    set<long long> s;
    for(long long i=1; i<(1LL<<32); i++){
        f*=i;
        f%=MM;
        if(i%70000==0){
            s.insert(f);
        }
    }
    printf("%d\n",s.size());
    // fclose(fi);
    return 0;
}
