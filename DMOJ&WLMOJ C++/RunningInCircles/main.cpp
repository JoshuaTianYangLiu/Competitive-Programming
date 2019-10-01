/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 25, 2019, 10:09 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    for(int a=0; a<5; a++){
        int size;
        scanf("%d",&size);
        vector<int> g[101];
        queue<int> q;
        int from,to;
        scanf("%d %d",&from,&to);
        q.push(from);
        int lv[101];
        lv[from]=1;
        g[from].push_back(to);
        for(int i=1; i<size; i++){
            scanf("%d %d",&from,&to);
            g[from].push_back(to);
        }
        bool check[101];
        memset(check,false,sizeof(check));
        bool b=true;
        
        while(!q.empty()&&b){
            int t=q.front();
            q.pop();
            check[t]=true;
            for(int i=0; i<g[t].size(); i++){
                if(check[g[t][i]]){
                    printf("%d\n",lv[t]-lv[g[t][i]]+1);
                    b=false;
                    break;
                }else{
                    lv[g[t][i]]=lv[t]+1;
                    q.push(g[t][i]);
                }
            }
        }
    }

}

