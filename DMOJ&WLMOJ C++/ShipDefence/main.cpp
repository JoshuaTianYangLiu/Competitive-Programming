/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 10, 2019, 4:51 p.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
pair<int,int> def[6];
int timeLine[1003];
int main() {
    memset(timeLine,0,sizeof(timeLine));
    double h;
    int d,e,f;
    scanf("%d %d %d",&f,&d,&e);
    h=f;
    for(int i=0; i<d; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        def[i]={a,b};
    }
    for(int i=0; i<e; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        timeLine[a]+=c;
        timeLine[a+b]-=c;
    }
    for(int i=1; i<1003; i++){
        timeLine[i]+=timeLine[i-1];
    }
    for(int i=0; i<1003; i++){
        double m=1000000000;
        for(int j=0; j<d; j++){
            if(timeLine[i]-def[j].second<0){
                m=0;
                break;
            }else{
                m=min(m,(100-def[j].first)/100.0*(timeLine[i]-def[j].second));
            }
        }
        if(d==0)m=timeLine[i];
        h-=m;
    }
    if(h<=0){
        printf("DO A BARREL ROLL!\n");
    }else{
        printf("%.2f",h);
    }
}