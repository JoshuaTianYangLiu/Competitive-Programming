#include <bits/stdc++.h>

using namespace std;
int h[1002];
int main() {
    int cases;
    scanf("%d",&cases);
    for(int i=0; i<cases; i++){
        memset(h,0,sizeof(h));
        int l,w;
        scanf("%d %d\n",&l,&w);
        int ans=0;
        for(int j=0; j<l; j++){
            for(int k=0; k<w; k++){
                char a;
                scanf("%c",&a);
                while(a!='R'&&a!='F')scanf("%c",&a);
                if(a=='F')h[k]++;
                else h[k]=0;
            }
            stack<int> s;
            int area=0;
            for(int m=0; m<=w; m++){
                while(!s.empty()&&h[m]<=h[s.top()]){
                    int idx=s.top(); s.pop();
                    int pre=s.empty()?0:s.top()+1;
                    area=max(area,h[idx]*(m-pre));
                }
                s.push(m);
            }
            ans=max(ans,area);
        }
        printf("%d\n",ans*3);
    }
    return 0;
}
