/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 30, 2019, 10:36 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */

int add(int a[],int b[]){
    int i=0;
    bool carry=false;
    int temp=0;
    while(a[i]!=-1||b[i]!=-1||carry){
        if(a[i]==-1)a[i]=0;
        if(b[i]==-1)b[i]=0;
        if(carry){
            temp=a[i]+b[i]+1;
            carry=false;
        }else temp=a[i]+b[i];
        if(temp>9)carry=true;
        temp%=10;
        a[i]=temp;
        i++;
    }
    return i;
    
}

void getSupplemantValue(int b[],int len)
{
    bool nonZeroFound = true;
 
    for (int i=0;i<len;i++)
    {   
        if(b[i]==-1)b[i]=0;
        if (nonZeroFound&&b[i]==0){
            b[i] =0;
        }else if(nonZeroFound){
            b[i]=10-b[i];
            nonZeroFound=false;
        }else{
            b[i]=9-b[i];
        }
    }
    
}
void sub(int a[],int b[],int len){
    getSupplemantValue(b, len);
    int index=add(a,b);
    if (index>len)
    {
        bool lZero=true;
        for(int j=index-2;j>=0; j--){
            if(j!=0&&lZero&&a[j]==0){
                continue;
            }else{
                lZero=false;
            }
            printf("%d",a[j]);
        }
        printf("\n");
    }
    else
    {
      getSupplemantValue(a, len);
      bool lZero=true;
      printf("-");
        for(int j=index-1;j>=0; j--){
            if(lZero&&a[j]==0){
                continue;
            }else{
                lZero=false;

            }
            printf("%d",a[j]);
        }
        printf("\n");
      
    }
}
int main() {
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        char aS[100010];
        char bS[100010];
        scanf("%s",aS);
        scanf("%s",bS);
        int a[100010];
        int b[100010];
        for(int j=0; j<100010; j++){
            a[j]=-1;
            b[j]=-1;
        }
        bool aNeg=false;
        bool bNeg=false;
        for(int i=strlen(aS)-1; i>=0; i--){
            if(aS[i]=='-'){
                aNeg=true;
                continue;
            }
            a[strlen(aS)-i-1]=aS[i]-'0';
        }
        for(int i=strlen(bS)-1; i>=0; i--){
            if(bS[i]=='-'){
                bNeg=true;
                continue;
            }
            b[strlen(bS)-i-1]=bS[i]-'0';
        }
        if(bNeg^aNeg){
            if(bNeg)sub(a,b,max(strlen(aS),strlen(bS)-1));
            else sub(b,a,max(strlen(aS)-1,strlen(bS)));
        }
        else{
            if(aNeg&&bNeg)printf("-");
            int index=add(a,b);
            bool lZero=true;
            for(int j=index-1;j>=0; j--){
                if(lZero&&a[j]==0){
                    continue;
                }else{
                    lZero=false;
                }
                printf("%d",a[j]);
            }
            printf("\n");
        }
        
    }

}

