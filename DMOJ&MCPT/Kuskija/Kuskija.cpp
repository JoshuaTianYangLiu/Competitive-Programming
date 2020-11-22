#include <bits/stdc++.h>

using namespace std;
queue<int> t[3];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        t[a%3].push(a);
    }
    if(t[0].empty()&&(t[1].empty()||t[2].empty())){
        //Stupid hardcoding
        while(!t[1].empty()){
            printf("%d ",t[1].front());
            t[1].pop();
        }
        while(!t[2].empty()){
            printf("%d ",t[2].front());
            t[2].pop();
        }
        printf("\n");
        return 0;
    }
    if(t[1].size()+t[2].size()<t[0].size()-1){
        printf("impossible\n");
        return 0;
    }
    while(t[1].size()>=t[0].size()){
        printf("%d ",t[1].front());
        t[1].pop();
    }
    while(!t[0].empty()&&!t[1].empty()){
        printf("%d %d ",t[0].front(),t[1].front());
        t[0].pop();t[1].pop();
    }
    while(!t[0].empty()&&!t[2].empty()){
        printf("%d %d ",t[0].front(),t[2].front());
        t[0].pop();t[2].pop();
    }
    while(!t[2].empty()){
        printf("%d ",t[2].front());
        t[2].pop();
    }
    if(t[1].size()+t[2].size()==t[0].size()-1){
        printf("%d ",t[0].front());
        t[0].pop();
    }
    printf("\n");
    return 0;
}
