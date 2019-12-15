#include <bits/stdc++.h>

using namespace std;
struct glass{int x1,y1,x2,y2,t;}g[1010];
int coordx[2020],coordy[2020];
unordered_map<int,int> um[2];
int main() {
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d %d",g[i].x1,g[i].y1,g[i].x2,g[i].y2,g[i].t);
        coordx[2*i]=g[i].x1;
        coordx[2*i+1]=g[i].x2;
        coordy[2*i]=g[i].y1;
        coordy[2*i+1]=g[i].y2;
    }
    sort(begin(coordx),begin(coordx)+2*n);
    sort(begin(coordy),begin(coordy)+2*n);
    for(int i=0; i<2*n; i++){
        
    }
    return 0;
}