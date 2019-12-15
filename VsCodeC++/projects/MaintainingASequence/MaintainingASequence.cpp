#include <bits/stdc++.h>

using namespace std;
int psum[100010];
char in[20];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    bool hasPos=false;
    int melm=INT_MIN;
    int ma=0,mb=0;
    for (int i = 1; i <= n; i++){
        scanf("%d",&psum[i]);
        ma+=psum[i];
        ma=max(ma,0);
        mb=max(ma,mb);
        if(psum[i]>=0)hasPos=true;
        melm=max(melm,psum[i]);
        psum[i]+=psum[i-1];
    }
    if(!hasPos)ma=melm;
    else ma=mb;
    bool isRev=false;
    while(m--){
        scanf("%s",in);
        if(in[0]=='G'){
            int a,b;
            scanf("%d %d",&a,&b);
            if(!isRev) printf("%d\n",psum[a+b-1]-psum[a-1]);
            else printf("%d\n",psum[n-a+1]-psum[n-a-b+1]);
        }else if(in[0]=='M') printf("%d\n",ma);
        else isRev=!isRev;
    }
    return 0;
}