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
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
 * 
 */
int findSet(int a,int *p[]){
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
            scanf("%c",&a);
            int in1=0;
            int in2=0;
            char in[255];
            scanf("%s",in);
            if(h.find(in)==h.end()){
                h[in]=count++;
            }
            unordered_map<string, int>::iterator it;
            it=h.find(in);
            in1=it->second;
            scanf("%s",in);
            if(h.find(in)==h.end()){
                h[in]=count++;
            }
            in2=h.find(in);
            if(a=='p'){


                //ranks
                int tempA=findSet(in1);
                int tempB=findSet(in2);

                int rank1 = rank[findSet(in1,&p)];
                int rank2 = rank[findSet(in2,&p)];

                //union
                if(rank1>rank2){
                    p[in2]=in1;
                    rank[in1]++;
                }else{
                    p[in1]=in2;
                    rank[in2]++;
                }
            }else{
                if(findSet(in1,&p)==findSet(in2,&p))printf("connected");
                else printf("not connected");
            }
        }
    }
}

