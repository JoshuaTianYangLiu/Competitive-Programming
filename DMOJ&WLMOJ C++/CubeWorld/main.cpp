/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 8, 2019, 2:28 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int in[20][20];
int up[20][20],down[20][20],lef[20][20],righ[20][20];
int main() {
    for(int a=0; a<5; a++){
        memset(in,0,sizeof(in));
        memset(up,0,sizeof(up));
        memset(down,0,sizeof(down));
        memset(lef,0,sizeof(lef));
        memset(righ,0,sizeof(righ));
        int m,n;
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)scanf("%d",&in[i][j]);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j!=0)lef[i][j]=max(in[i][j],lef[i][j-1]);
                else lef[i][j]=in[i][j];
                
            }
        }
        for(int i=0; i<m; i++){
            for(int j=n-1; j>=0; j--){
                if(j!=n-1)righ[i][j]=max(in[i][j],righ[i][j+1]);
                else righ[i][j]=in[i][j];
                
            }
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                if(i!=0)up[i][j]=max(in[i][j],up[i-1][j]);
                else up[i][j]=in[i][j];
                
            }
        }
        for(int j=0; j<n; j++){
            for(int i=m-1; i>=0; i--){
                if(i!=m-1)down[i][j]=max(in[i][j],down[i+1][j]);
                else down[i][j]=in[i][j];
                
            }
        }
        long out=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                out+=min(min(up[i][j],down[i][j]),min(lef[i][j],righ[i][j]))-in[i][j];
                printf("%d ",min(min(up[i][j],down[i][j]),min(lef[i][j],righ[i][j]))-in[i][j]);
            }
            printf("\n");
        }
        printf("%d\n",out);
    }

}

