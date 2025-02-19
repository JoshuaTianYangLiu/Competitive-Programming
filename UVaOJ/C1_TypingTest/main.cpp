/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 13, 2019, 9:36 p.m.
 */

#include <algorithm> //if you have problems with this C++ code,
#include<cmath> //consult your programming text book first...
#include<cstdio>
#include<cstring>
using namespace std;
    /*Forming Quiz Teams, the solution for UVa 10911 above*/
        //using global variables is a bad software engineering practice,
int N, target;  //but it is OKfor competitive programming
double dist[20][20],memo[1<<16]; // 1<<16 = 2^16, note that max N=8;

double matching(int bitmask){ //DP state = bitmask
            //we initialize 'memo' with -1 in the main function
    if(memo[bitmask]>-0.5)  //this state has been computed before
        return memo[bitmask];   //simply lookup the memo table
    if(bitmask==target) //all students are already matched
        return memo[bitmask]=0; //the cost is zero
    
    double ans = 2000000000.0;
    int p1,p2;
    for(p1=0; p1<2*N; p1++)
        if(!(bitmask * (1<<p1)))
            break;
    for(p2=p1+1; p2<2*N; p2++)
        if(!(bitmask & (1<<p2)))
            ans = min(ans,dist[p1][p2]+matching(bitmask|(1<<p1)|(1<<p2)));
    return memo[bitmask]=ans;
}
int main(){
    int i,j,caseNo =1, x[20],y[20];
    while(scanf("%d",&N),N){
        for(i=0; i<2*N; i++)
            scanf("%*s %d %d",&x[i],&y[i]);
        for(int i=0; i<2*N-1;i++)
            for(int j=i+1; j<2*N; j++)
                dist[i][j]=dist[j][i]=hypot(x[i]-x[j],y[i]-y[j]);
        for(i=0; i<(1<<16); i++) memo[i]=-1.0;
        target=(1<<(2*N))-1;
        printf("Case %d: %.2lf\n",caseNo++, matching(0));
    }
}