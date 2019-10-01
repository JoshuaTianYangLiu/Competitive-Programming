/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 26, 2019, 10:12 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int p[100001];
int r[100001];

int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (r[x] > r[y]) p[y] = x;
        else { 
            p[x] = y;
            if (r[x] == r[y]) r[y]++; 
        }
    } 
}
int main() {
    int node,edges;
    scanf("%d %d",&node,&edges);
    memset(r,0,sizeof(r));
    queue<int> q;
    for(int i=1; i<=node; i++)p[i]=i;
    for(int i=0; i<edges; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(!isSameSet(a,b)){
            q.push(i+1);
            unionSet(a,b);
        }
    }
    int numOfRoot=0;
    for(int i=1;i<=node; i++){
        if(p[i]==i)numOfRoot++;
    }
    if(numOfRoot==1){
        while(!q.empty()){
            printf("%d\n",q.front());
            q.pop();
        }
    }else{
        printf("Disconnected Graph");
    }
}

