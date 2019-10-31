/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 6, 2019, 4:43 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int kn[100][100];
int eh(int pr,int pc,int r){
    int moves=0;
    if(kn[pr+1][pc]==moves){
        printf("Stalemate in %d knight move(s).\n",kn[pr+1][pc]);
        return 0;
    }
    int m=2000;
    while(pr<r){
        pr++;
        moves++;
        if(kn[pr][pc]==moves){
            printf("Win in %d knight move(s).\n",kn[pr][pc]);
            return 0;
        }else if(kn[pr+1][pc]==moves){
            printf("Stalemate in %d knight move(s).\n",kn[pr+1][pc]);
            return 0;
        }else if(moves-kn[pr][pc]>=0&&(moves-kn[pr][pc])%2==0&&m==2000){
            m=min(m,moves);
        }
    }
    if(m<moves-1)printf("Win in %d knight move(s).\n",m);
    else printf("Loss in %d knight move(s).\n",moves-1);
    return 0;
}
int main() {
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        int r,c,pr,pc,kr,kc;
        scanf("%d %d %d %d %d %d",&r,&c,&pr,&pc,&kr,&kc);
        for(int j=0; j<=r; j++){
            for(int k=0; k<=c; k++){
                kn[j][k]=2000;
            }
        }
        queue<pair<int,int>> q;
        kn[kr][kc]=0;
        q.push({kr,kc});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int a=x+2;
            int b=y+1;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
            a=x+2;
            b=y-1;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
            a=x+1;
            b=y+2;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
            a=x+1;
            b=y-2;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
            a=x-1;
            b=y+2;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
            a=x-1;
            b=y-2;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
            a=x-2;
            b=y+1;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
            a=x-2;
            b=y-1;
            if(a<=r&&b<=c&&a>0&&b>0){
                if(kn[x][y]+1<kn[a][b]){
                    kn[a][b]=min(kn[x][y]+1,kn[a][b]);
                    q.push({a,b});
                }
            }
        }
//        for(int j=1; j<=r; j++){
//            for(int k=1; k<=c; k++){
//                printf("%d ",kn[j][k]);
//            }
//            printf("\n");
//        }
        eh(pr,pc,r);
    }

}

