/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 18, 2019, 8:30 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int flip(int a){return abs(a-1);}
int saves[1<<20];
vector<int> keysIn;
int main() {
    int size,times;
    scanf("%d %d",&size,&times);
    memset(saves,0,sizeof(saves));
    for(int i=0; i<times; i++){
        int t[11][11];
        char in[11];
        for(int j=0; j<size; j++){
            scanf("%s",in);
            for(int k=0; k<size; k++){
                t[j][k]=in[k]=='R'?1:0;
            }
        }
        for(int j=0; j<size-1; j++){
            for(int k=0; k<size-1; k++){
                if(t[j][k]==1){
                    t[j][k]=flip(t[j][k]);
                    t[j][k+1]=flip(t[j][k+1]);
                    t[j+1][k+1]=flip(t[j+1][k+1]);
                    t[j+1][k]=flip(t[j+1][k]);
                }
            }
        }
        int key=0;
        for(int j=0; j<size; j++){
            key<<=1;
            key+=t[size-1][j];
        }
        for(int j=0; j<size; j++){
            key<<=1;
            key+=t[j][size-1];
        }
        if(saves[key]==0)keysIn.push_back(key);
        saves[key]++;
    }
    int out=0;
    for(int i=0; i<keysIn.size(); i++){
        if(saves[keysIn[i]]!=1&&saves[keysIn[i]]!=0){
            out+=(saves[keysIn[i]]*(saves[keysIn[i]]-1))/2;
        }
    }
    printf("%d",out);
}

