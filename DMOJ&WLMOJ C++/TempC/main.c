/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Joshua
 *
 * Created on March 26, 2019, 10:12 p.m.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int size;
    scanf("%d\n",&size);
    int total=0;
    int temp=0;
    char curChar='1';
    char temp2[20];
    char a;
    for(int i=0; i<size; i++){
        scanf("%s",temp2);
        a=temp2[0];
        if(a>96)a-=32;
        if(curChar==a)temp++;
        else{
            total+=(temp*(temp+1))/2;
            total%=1000000007;
            temp=1;
            curChar=a;
        }
    }
    total+=(temp*(temp+1))/2;
    total%=1000000007;
    printf("%d\n",total);
    return 0;
}

