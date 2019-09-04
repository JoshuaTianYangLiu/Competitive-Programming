/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 18, 2019, 5:46 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 *
 */
 int g[401][401];
int f(int a,int b, int c, int d){
    return g[c][d]-g[a-1][d]-g[c][b-1]+g[a-1][b-1];
}
int main() {
    memset(g,0,sizeof(g));
    int l,w;
    scanf("%d %d",&l,&w);
    for(int i=1; i<=l; i++){
        char in[401];
        scanf("%s",in);
        for(int j=1; j<=w; j++){
            //Do prefix while reading
            if(in[j-1]=='X'){
                g[i][j]++;
            }
            g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1; i<=l; i++){
        for(int j=i; j<=l; j++){
                int maxL=0;
                int curL=0;
            for(int k=1; k<=w; k++){
                if(f(i,k,j,k)==0){
                    curL++;
                }else{
                    maxL=max(maxL,curL);
                    curL=0;
                }
            }
                maxL=max(maxL,curL);
            if(maxL>0){
                ans=max(ans,2*(maxL+j-i+1));
            }
        }
    }
    printf("%d",ans-1);
}

