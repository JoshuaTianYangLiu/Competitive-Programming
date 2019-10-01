#include <bits/stdc++.h>

using namespace std;

int main() {
    char a[1001];
    char b[1001],c[1001];
    scanf("%[^\n]",a);
    for(int i=0; i<strlen(a); i++){
        for(int j=33; j<127; j++){
            if(!isalnum(j)&&!isalnum(a[i]^j)){
                if((a[i]^j)>32&&(a[i]^j)<127){
                    printf("%c",a[i]);
                    // break;
                }
            }
            
        }
        // printf(" %c\n",a[i]);
    }
    printf("\n");
    for(int i=0; i<strlen(a); i++){
        for(int j=33; j<127; j++){
            if(!isalnum(j)&&!isalnum(a[i]^j)){
                if((a[i]^j)>32&&(a[i]^j)<127){
                    printf("%c",j);
                    // break;
                }
            }
            
        }
        // printf(" %c\n",a[i]);
    
    }
    printf("\n");
    for(int i=0; i<strlen(a); i++){
        for(int j=33; j<127; j++){
            if(!isalnum(j)&&!isalnum(a[i]^j)){
                if((a[i]^j)>32&&(a[i]^j)<127){
                    printf("%c",a[i]^j);
                    // break;
                }
            }
            
        }
        // printf(" %c\n",a[i]);
    }
    printf("\n");
    // printf("%s\n%s\n%s\n",a,b,c);
    printf("Finished");
    return 0;
}
