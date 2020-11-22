#include <bits/stdc++.h>
 
using namespace std;
struct ring {
    int x,y,r,R;
};
bool inside(pair<int,int> p1,pair<int,int> p2,int r1,int r2){
    int d =(p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
    if(r1>r2)
        if(d<=(r1-r2)*(r1-r2))return true;
    return false;
}
bool intersect(pair<int,int> p1,pair<int,int> p2,int r1,int r2){
    int d =(p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
    if(d>=(r1+r2)*(r1+r2))return false;
    if(d<=(max(r1,r2)-min(r1,r2))*(max(r1,r2)-min(r1,r2)))return false;
    return true;
}
bool overlap(pair<int,int> p1,pair<int,int> p2,int r1,int r2){
	int d =(p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
	return d<(r1+r2)*(r1+r2);
}
 
int main() {
    ring a;`~
    ring b;
    scanf("%d %d %d %d",&a.x,&a.y,&a.r,&a.R);
    scanf("%d %d %d %d",&b.x,&b.y,&b.r,&b.R);
    int ans=0;
    pair<int,int> aa={a.x,a.y},bb={b.x,b.y};
    // a inner
    if(!intersect(aa,bb,a.r,b.r)&&!intersect(aa,bb,a.r,b.R))ans++;
    if(!intersect(aa,bb,a.R,b.r)&&!intersect(aa,bb,a.R,b.R))ans++;
    if(!intersect(aa,bb,a.r,b.r)&&!intersect(aa,bb,a.R,b.r))ans++;
    if(!intersect(aa,bb,a.r,b.R)&&!intersect(aa,bb,a.R,b.R))ans++;
    if(inside(aa,bb,a.R,b.R)&&!overlap(aa,bb,a.r,b.r)&&!overlap(aa,bb,a.r,b.R))ans=2;
    if(inside(bb,aa,b.R,a.R)&&!overlap(bb,aa,b.r,a.r)&&!overlap(bb,aa,b.r,a.R))ans=2;
    if(inside(aa,bb,a.R,b.R)&&inside(bb,aa,b.R,a.r)&&inside(aa,bb,a.r,b.r))ans=2;
    if(inside(bb,aa,b.R,a.R)&&inside(aa,bb,a.R,b.r)&&inside(bb,aa,b.r,a.r))ans=2;
    printf("%d\n",ans);
    return 0;
}