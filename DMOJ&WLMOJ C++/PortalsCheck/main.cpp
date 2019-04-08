/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 25, 2019, 5:02 p.m.
 */

#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int findSet(int a,int p[]){
    while(p[a]!=a){  
        a=p[a];
    }
    return a;
}
int main() {
    map<string,int> h;
    for(int i=0; i<5; i++){
        h.clear();
        int q;
        scanf("%d",&q);
        int count=0;
        int rank[q] ;
        int p[q];
        for(int j=0; j<q; j++){
            p[j]=j;
        }
        for(int j=0; j<q; j++){
            char a;
            scanf(" %c",&a);
            int in1=0;
            int in2=0;
            char in[255];
            scanf("%s",in);
            if(h.find(in)==h.end()){
                h[in]=count++;
            }
            in1=h[in];
            scanf("%s",in);
            if(h.find(in)==h.end()){
                h[in]=count++;
            }
            in2=h[in];
            if(a=='p'){


                int x=findSet(in1,p);
                int y=findSet(in2,p);

                if (rank[x]>rank[y]) p[y] =x;
                else p[x]=y;
                if(rank[x]==rank[y])rank[x]++;
            }else{
                if(findSet(in1,p)==findSet(in2,p))printf("connected\n");
                else printf("not connected\n");
            }
        }
    }
}

