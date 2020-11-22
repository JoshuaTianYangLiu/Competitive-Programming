#include <bits/stdc++.h>

using namespace std;
int memo[300][300][300];
int n;
double N;
double f(int one,int two,int three){
    if(one==0&&two==0&&three==0)return 0;
    double ret=0;
    double ree=0;
    if(one>0)ret+=f(one-1,two,three);
    if(two>0)ret+=f(one+1,two-1,three);
    if(three>0)ret+=f(one,two+1,three-1);
    if(one>0)ree=N/one;
    if(two>0)ree=N/two;
    if(three>0)ree=N/three;
    printf("%d %d %d %.6lf\n",one,two,three,ree);
    return ret+ree;
}
int main() {
    scanf("%d",&n);
    N=n;
    int one=0,two=0,three=0;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d",&a);
        if(a==1)one++;
        if(a==2)two++;
        if(a==3)three++;
    }
    printf("%.6lf\n",f(one,two,three));
    return 0;
}