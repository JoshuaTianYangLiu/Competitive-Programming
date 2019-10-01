#include <bits/stdc++.h>

using namespace std;
int in[100002];
int main() {
    memset(in,-1,sizeof(in));
    int n,m,j;
    scanf("%d %d %d",&n,&m,&j);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        in[a]=b;
    }
    deque<int> dq;
    in[0]=0;
    in[n+1]=0;
    dq.push_back(0);
    for(int l=0,r=1; r<=n+1; r++){
        while(l<r-j){
            if(dq.empty()){
                printf("-1");
                return 0;
            }
            if(dq.front()==in[l])dq.pop_front();
            l++;
        }
        if(!dq.empty()&&(in[r]!=-1)){
            in[r]=max(in[r],dq.front());
        }
        while(!dq.empty()&&dq.back()>in[r]&&in[r]!=-1){
            dq.pop_back();
        }
        if(in[r]!=-1){
            dq.push_back(in[r]);
        }
        

    }
    printf("%d",dq.front());
    return 0;
}