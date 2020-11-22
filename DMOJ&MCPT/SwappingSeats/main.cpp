#include <bits/stdc++.h>

using namespace std;
int ps[2000020][3];
char in[1000010];
int ans1[2000020][3];
int numOf[3];
int len;
int solve(int i){
    //A
    int a=numOf[0],b=numOf[1],c=numOf[2];
    int ABC=ans1[i][0]+ans1[i+b][1]+ans1[i+b+c][2];
    int ACB=ans1[i][0]+ans1[i+c][2]+ans1[i+b+c][1];
    int BAC=ans1[i][1]+ans1[i+a][0]+ans1[i+a+c][2];
    int BCA=ans1[i][1]+ans1[i+c][2]+ans1[i+a+c][0];
    int CAB=ans1[i][2]+ans1[i+a][0]+ans1[i+a+b][1];
    int CBA=ans1[i][2]+ans1[i+b][1]+ans1[i+b+a][0];
    // printf("%d %d %d %d %d %d %d\n",i,ABC,ACB,BAC,BCA,CAB,CBA);
    return min(ABC,min(ACB,min(BAC,min(BCA,min(CAB,CBA)))));
}
int main(){
    scanf("%s",in);
    len=strlen(in);
    for(int i=0; i<len; i++){
            ps[i][in[i]-'A']++;
            ps[i+len][in[i]-'A']++;
            numOf[in[i]-'A']++;
    }
    for(int i=1; i<2*len; i++){
        for(int j=0; j<3; j++)ps[i][j]+=ps[i-1][j];
    }
    memset(ans1,0x3f,sizeof(ans1));
    int ans=2e9;
    for(int h=0; h<3; h++){
        for(int i=numOf[h]; i<2*len; i++){
            int l=i-numOf[h]+1,r=i;
            ans1[i][h]=numOf[h]-(ps[r][h]-ps[l-1][h]);
        }
    }
    int finalAns=2e9;
    for(int i=0; i<2*len; i++){
        // printf("%d ",solve(i,0));
        finalAns=min(finalAns,solve(i));
    }
    // for(int i=0; i<3; i++){
    //     // printf("%d: ",i);
    //     for(int j=0; j<2*len; j++){
    //         // printf("%d ",ans1[j][i]);
    //     }
    //     // printf("\n");
    // }
    printf("%d %d\n",finalAns,(finalAns+1)/2);
    return 0;
}