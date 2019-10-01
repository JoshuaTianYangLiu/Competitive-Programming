#include <bits/stdc++.h>

using namespace std;
long long fSize[31];
char baseSentence[46]={"Good writing is good writing is good writing."};
char leftSen[22]={"Good writing is good "};
char midSen[18]={" writing is good "};
char riSen[18]={" is good writing."};
int main() {
    long long n=45;
    for(int i=0; i<31; i++){
        // printf("%d %lld\n",i,n);
        fSize[i]=n;
        n=55+2*n;
    }
    int q;
    scanf("%d",&q);
    for(int i=0,size,k; i<q; i++){
        scanf("%d %d",&size,&k);
        while(true){
            if(size==0&&k<=45){
                printf("%c\n",baseSentence[k-1]);
                break;
            }else if(size==0){
                printf(".\n");
                break;
            }else if(k<=21){
                printf("%c\n",leftSen[k-1]);
                break;
            }else if(k<=fSize[size-1]+21){
                k-=21;
                size--;
            }else if(k<=38+fSize[size-1]){
                printf("%c\n",midSen[k-1-38-fSize[size-1]]);
                break;
            }else if(k<=38+2*fSize[size-1]){
                k-=38+fSize[size-1];
                size--;
            }else if(k<=55+2*fSize[size-1]){
                printf("%c\n",riSen[k-55-2*fSize[size-1]-1]);
                break;
            }else{
                printf(".\n");
                break;
            }
        }

    }
    return 0;
}
