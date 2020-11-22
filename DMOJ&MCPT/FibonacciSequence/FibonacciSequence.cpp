#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
#define NN 2000000016
char in[100001];
struct f{long long a,b,c,d;};
f def={1,0,0,1};
f mul(f n,f m){
    f temp;
    temp.a=((n.a*m.a)%MM+(n.b*m.c)%MM)%MM;
    temp.b=((n.a*m.b)%MM+(n.b*m.d)%MM)%MM;
    temp.c=((n.c*m.a)%MM+(n.d*m.c)%MM)%MM;
    temp.d=((n.c*m.b)%MM+(n.d*m.d)%MM)%MM;
    return temp;
}
f fpm(f base,long long pow){
    if(pow==0)return def;
    if(pow==1)return base;
    if(pow%2==0)return fpm(mul(base,base),pow/2);
    return mul(base,fpm(mul(base,base),pow/2));
}
int main() {
    scanf("%s",in);
    long long pmt=1;
    long long pisano=0;
    for(int i=strlen(in)-1; i>=0; i--){
        pisano=(pisano+pmt*(in[i]-'0'))%NN;
        pmt=(pmt*10)%NN;
    }
    f t={0,1,1,1};
    printf("%lld\n",fpm(t,pisano).b);
    return 0;
}
