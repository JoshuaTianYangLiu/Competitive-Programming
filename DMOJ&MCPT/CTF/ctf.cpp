#include <bits/stdc++.h>

using namespace std;
long long s[20];
int memo[100000];
int f(int a){
    if(a<4){
        return a+5;
    }
    if(memo[a]!=-1)return memo[a];
    // printf("::%d\n",a);
    // printf("%d %d\n",a,a-5);
    int iVar2 = f(a - 1);
    // printf("Calling\n");
    int iVar3 = f(a-5);
    // printf("Called\n");
    // int lVar6 = a / 3;
    int iVar4 = f(a/3);
    double dVar7 = sqrt(a);
    int iVar5 = f((int)dVar7);
    int uVar1 = (iVar5 * 3 + iVar2 + iVar3 + iVar4 * 2) / 3;
    memo[a]=uVar1;
    return uVar1;
}
int main() {
    memset(memo,-1,sizeof(memo));
    s[0/4] = f(0xb21f);
    s[4/4] = f(0xbb2e);
    s[8/4] = f(0xc41a);
    s[12/4] = f(0xa64b);
    s[16/4] = f(0xc0b2);
    s[20/4] = f(0xe6ab);
    s[24/4] = f(0xb5c1);
    s[28/4] = f(0xa629);
    s[32/4] = f(0xd5d5);
    s[36/4] = f(0xab6e);
    s[40/4] = f(0xb21f);
    s[44/4] = f(0xbae9);
    s[48/4] = f(0xb181);  
    s[52/4] = f(f(0x5c82));
    s[56/4] = f(f(0x6d02));
    // iVar1 = f(5);
    // uVar2 = f(0xb4aa);
    // *(undefined4 *)(s + (long)iVar1 * 4) = uVar2; Should be for s[60/4] but really used for s[68/4] ?????
    s[60/4] = f(0xb4aa);
    s[64/4] = f(0x4753);
    s[68/4] = f(0xadc7);
    s[72/4] = f(0xf959);
    printf("HI");
    int cnt = 0;
    while (cnt < 19) {
        int var = s[cnt];  // var = s[cnt]
        if (var < 0) {
            var = var + 0xff;
        }
        putchar(var >> 8);
        if ((s[cnt] & 0xff) != 0) {
            int uVar3 = s[cnt] >> 0x18;
            putchar((s[cnt] + uVar3 & 0xff) - uVar3);
        }
        cnt = cnt + 1;
    }
    return 0;
}