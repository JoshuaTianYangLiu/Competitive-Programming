/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 15, 2019, 11:12 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
pair<int,int> point[1001][1001];
char in[1001];
int rank1[1001][1001];

pair<int,int> fSet(pair<int,int> a){ return point[a.first][a.second]==a?a:point[a.first][a.second]=fSet(point[a.first][a.second]);}
bool isSameSet(pair<int,int> a,pair<int,int> b){return fSet(a)==fSet(b);}
void uSet(pair<int,int> a, pair<int,int> b){
    if(!isSameSet(a,b)){
        pair<int,int> x=fSet(a),y=fSet(b);
        if(rank1[x.first][x.second]>rank1[y.first][y.second])point[y.first][y.second]=x;
        else{
            point[x.first][x.second]=y;
            if(rank1[x.first][x.second]==rank1[y.first][y.second])
                rank1[y.first][y.second]++;
        }
    }
}
int main() {
    int n,m;
    memset(rank1,0,sizeof(rank1));
    scanf("%d %d\n",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)point[i][j]={i,j};
    }
    for(int i=0; i<n; i++){
        scanf("%s",in);
        for(int j=0; j<m; j++){
            if(in[j]=='S')uSet({i,j},{i+1,j});
            else if(in[j]=='W')uSet({i,j},{i,j-1});
            else if(in[j]=='E')uSet({i,j},{i,j+1});
            else uSet({i,j},{i-1,j});
//            printf("%c",in[j]);
        }
//        printf("\n");
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pair<int,int> t={i,j};
            if(point[i][j]==t)cnt++;
            printf("%d %d, %d %d\t",i,j,point[i][j].first,point[i][j].second);
        }
        printf("\n");
    }
    printf("%d",cnt);
}

