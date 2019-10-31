/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 17, 2019, 4:20 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int a[10000];
int findSet(int b){
    while(a[b]!=b){  
        b=a[b];
    }
    return b;
}
int main() {
    int size;
    scanf("%d",&size);
    
    int rank[10000];
    memset(rank,1,sizeof(rank));
    for(int i=0; i<10000; i++)a[i]=i;
    for(int i=0; i<size; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        x=findSet(x);
        y=findSet(y);

        if (rank[x]>rank[y]) a[y] =x;
        else a[x]=y;
        if(rank[x]==rank[y])rank[x]++;
    }
    int q1,q2;
    scanf("%d %d",&q1,&q2);
    while(q1!=0&&q2!=0){
        int setQ1=findSet(q1);
        int setQ2=findSet(q2);
        if(setQ1==setQ2)printf("Yes\n");
        else printf("No\n");
        scanf("%d %d",&q1,&q2);
    }
}

