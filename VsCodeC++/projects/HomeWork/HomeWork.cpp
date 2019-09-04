#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
pair<float,int> in[1000001];
bool hw[1000001];
int main() {
    for(int a=0; a<10; a++){
        memset(hw,false,sizeof(hw));
        int size;
        scanf("%d",&size);
        for(int i=0; i<size; i++){
            int b;
            float c;
            scanf("%d %f",&b,&c);
            in[i]={c,b};
        }
        sort(in,in+size);
        float out=0;
        for(int i=size-1; i>=0; i--){
            printf("%d %.4f\n",in[i].second,in[i].first);
            if(!hw[in[i].second])out+=in[i].first;
            hw[in[i].second]=true;
        }
        printf("%.4f\n",out);
    }

}