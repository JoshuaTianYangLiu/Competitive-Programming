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
bool dp[20][20][51];
int m,n;
void f(int x,int y,int z){
    if(!dp[x][y][z]){
        if(in[x][y]>=z){
            dp[x][y][z]=true;
        }else{
            dp[x][y][z]=true;
            if(x-1>=0)f(x-1,y,z);
            if(y-1>=0)f(x,y-1,z);
            if(x+1<m)f(x+1,y,z);
            if(y+1<n)f(x,y+1,z);
            
        }
    }
    
}
int main() {
    for(int a=0; a<5; a++){
        memset(in,0,sizeof(in));
        memset(dp,false,sizeof(dp));
        
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)scanf("%d",&in[i][j]);
        }
        int tot=0;
        for(int i=1; i<51; i++){
            for(int j=0; j<m; j++){
                f(j,0,i);
                f(j,n-1,i);
            }
            for(int j=0; j<n; j++){
                f(0,j,i);
                f(m-1,j,i);
            }
            for(int j=0; j<m; j++){
                for(int k=0; k<n; k++){
                    if(in[j][k]<i&&!dp[j][k][i])tot++;//printf("%d ",1);
                    //printf("%d ",dp[j][k][i]?1:0);
                }
//                printf("\n");
            }
//            printf("\n");
        }
        printf("%d\n",tot);
    }

}