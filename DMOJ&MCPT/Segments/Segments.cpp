#include <bits/stdc++.h>

using namespace std;
int n;
int f(int a,int b,int c,int d){
    if(a>=b&&a<=c){
        int goLeft=a-b+c-b+abs(d-c);
        int goRight=c-a+c-b+abs(d-b);
        return min(goLeft,goRight);
    }else{
        int turn=a<b?c:b;
        return abs(a-turn)+abs(turn-d);
    }
}
int main() {
    scanf("%d",&n);
    pair<int,int> a,b;
    scanf("%d %d",&a.first,&a.second);
    int ans=0,pos=1;
    for(int i=1; i<n; i++){
        scanf("%d %d",&b.first,&b.second);
        //I wanna die (Fix this code pls)
        int yes=0;
        if(pos>=a.first&&pos<=a.second){
            int leftPoint=f(pos,a.first,a.second,b.first);
            int rightPoint=f(pos,a.first,a.second,b.second);
            yes=min(leftPoint,rightPoint);
            ans+=yes;
            if(leftPoint>rightPoint)pos=b.second;
            else pos=b.first;
        }else{
            int turn=pos<a.first?a.second:a.first;
            yes=f(pos,a.first,a.second,turn);
            ans+=yes;
            pos=turn;
        }
        printf("::%d\n",yes);
        a=b;
    }
    ans+=f(pos,a.first,a.second,n);
    printf("%d",ans);
    return 0;
}