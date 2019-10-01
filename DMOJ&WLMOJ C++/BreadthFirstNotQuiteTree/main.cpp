/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 21, 2019, 12:47 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    for(int i=0; i<5; i++){
        int size;
        scanf("%d",&size);
        vector<int> g[100];
        for(int j=0; j<size; j++){
            int t,u;
            scanf("%d %d",&t,&u);
            g[t].push_back(u);
            g[u].push_back(t);
        }
        queue<int> q;
        q.push(1);
        bool checked[100];
        memset(checked,false,sizeof(checked));
        int lv[100];
        memset(lv,-1,sizeof(lv));
        checked[1]=true;
        lv[1]=0;
        int cnt=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int j=0; j<g[a].size(); j++){
                if(!checked[g[a][j]]){
                    q.push(g[a][j]);
                    lv[g[a][j]]=lv[a]+1;
                    checked[g[a][j]]=true;
                }else{
                    if(lv[g[a][j]]==lv[a]){
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt/2);
    }

}

