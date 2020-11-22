#include <bits/stdc++.h>

using namespace std;
pair<char,int> charl[1010],bot[1010];
int main() {
    int n,h;
    scanf("%d %d\n",&n,&h);
    int bh=h,ch=h;
    for(int i=1; i<=n; i++)scanf("%c %d\n",&charl[i].first,&charl[i].second);
    for(int i=1; i<n; i++)scanf("%c %d\n",&bot[i].first,&bot[i].second);
    scanf("%c %d",&bot[n].first,&bot[n].second);
    for(int i=1; i<=n; i++){
        // printf("%d %d\n",ch,bh);
        if(charl[i].first=='A'){
            if(bot[i-1].first!='D'){
                bh-=charl[i].second;
                if(bh<=0){
                    printf("VICTORY\n");
                    return 0;
                }
            }
        }else{
            if(bot[i].first!='A'){
                ch-=charl[i].second;
                if(ch<=0){
                    printf("DEFEAT\n");
                    return 0;
                }
            }
        }
        if(bot[i].first=='A'){
            if(charl[i].first!='D'){
                ch-=bot[i].second;
                if(ch<=0){
                    printf("DEFEAT\n");
                    return 0;
                }
            }
        }else{
            if(charl[i+1].first!='A'){
                bh-=bot[i].second;
                if(bh<=0){
                    printf("VICTORY\n");
                    return 0;
                }
            }
        }
    }
    printf("TIE\n");
    return 0;
}