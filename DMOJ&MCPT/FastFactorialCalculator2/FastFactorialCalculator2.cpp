#include <bits/stdc++.h>

using namespace std;
int conv(int a){
    assert(a!=139);
    if(a==92)return 139;
    if(a<=10)return 121+a;
    if(a<=20)return 133+a-10;
    if(a<=30)return 12183+a-20;
    if(a<=32)return 32787+a-30;
    if(a>0xd7ff&&a<0xe000)return a+0x100000;
    return a;
}
int main() {
    // Ty https://r12a.github.io/app-conversion/
    freopen("FFC2","w",stdout);
    unsigned long long f=1;
    for(long long i=1; i<4294967291ll; i++){
        f*=i;
        f%=4294967291ll;
        if(i%150000==0){
            long long g=(long long)f;
            int a = g&0xffff;
            int b = ((g>>16)&0xffff);
            printf("%d %d ",conv(b),conv(a));
            // printf("%lld\n",f);
        }
    }
    fclose(stdout);
    return 0;
}