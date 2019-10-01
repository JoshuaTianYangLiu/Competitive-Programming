/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 22, 2019, 11:13 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int g[10000];
bool visited[10000];
int check(int s,int e){
    int curNum=s;
    int cnt=0;
    while(true){
        if(visited[curNum])return -1;
        visited[curNum]=true;
        if(curNum==e)return cnt;
        curNum=g[curNum];
        cnt++;
    }
}
int main() {
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a]=b;
    }
    int x,y;
    scanf("%d %d",&x,&y);
    while(!(x==0&&y==0)){
        memset(visited,false,sizeof(visited));
        int out=check(x,y);
        if(out==-1)printf("No\n");
        else printf("Yes %d\n",out-1);
        scanf("%d %d",&x,&y);
    }
}

