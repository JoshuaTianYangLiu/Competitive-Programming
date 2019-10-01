/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 22, 2019, 7:48 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
bool taken[11][11];
int find(int x,int y,int eX,int eY,int dir){
    int a=100000;
    //1 right
    //2 left
    //3 up
    //4 down
    if(x==eX&&y==eY)return 0;
    if(taken[y][x+1]&&dir!=2)a=min(a,find(x+1,y,eX,eY,1));
    if(x>0&&taken[y][x-1]&&dir!=1)a=min(a,find(x-1,y,eX,eY,2));
    if(taken[y+1][x]&&dir!=3)a=min(a,find(x,y+1,eX,eY,4));
    if(y>0&&taken[y-1][x]&&dir!=4)a=min(a,find(x,y-1,eX,eY,3));
    return a+1;
}
int main() {
    
    //Need to finish search
    for(int i=0; i<5; i++){
        int size1,size2;
        scanf("%d %d",&size1,&size2);
        memset(taken,true,sizeof(taken[0][0])*11*11);
        int a[2];
        int b[2];
        int c[2];
        for(int j=0; j<size1; j++){
            for(int k=0; k<size2; k++){
                char t;
                scanf("%c",&t);
                if(t=='#'){
                    taken[j][k]=false;
                }
                if(t=='A'){
                    a[0]=j;
                    a[1]=k;
                }
                if(t=='B'){
                    b[0]=j;
                    b[1]=k;
                }
                if(t=='C'){
                    c[0]=j;
                    c[1]=k;
                }
            }
        }
        printf("k\n");
        printf("%d",find(a[1],a[0],b[1],b[0],-1)+find(b[1],b[0],c[1],c[0],-1)+find(c[1],c[0],b[1],b[0],-1));
    }
}

