#include <bits/stdc++.h>

using namespace std;
FILE *f;
FILE *g;
char origBmp;
int main() {
    f=fopen("Item01_cp.bmp","r");
    for(int i=0; i<2019; i++){
    fread(&origBmp,1,1,f);
    // printf("\t\t%x\n",origBmp);
    }
    int i=0;
    while(i<50){
        if(i%5==0){
            int out=0;
            for(int j=0; j<8; j++){
                fread(&origBmp,1,1,f);
                out|=(origBmp&1)<<j;
            }
        printf("%c",out);
        }else{
            fread(&origBmp,1,1,f);
        }
        i++;
    }
    // for(int i=0; i<50; i++){
    //     int out=0;
    //     for(int j=0; j<8; j++){
    //         fread(&origBmp,1,1,f);
    //         out|=(origBmp&1)<<j;
    //     }
    //     printf("%c",out+5);
    // }
    fclose(f);
    return 0;
}

//codedChar(local_70,(acStack72[itit] + -5),origBmp,(acStack72[itit] +-5))