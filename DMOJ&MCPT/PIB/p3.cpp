#include <bits/stdc++.h>

using namespace std;
int in[100010],size[100010],ruleGroup[100010];
int main() {
    int ruleNum=1;
    int groupNum=1;
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&a);
        if(a==1){
            in[ruleNum]=1;
            ruleGroup[ruleNum]=ruleGroup[ruleNum-1]+1;
            size[ruleGroup[ruleNum]]=1;
            ruleNum++;
        }else if(a==2){
            in[ruleNum]=in[ruleNum-1]+1;
            ruleGroup[ruleNum]=ruleGroup[ruleNum-1];
            size[ruleGroup[ruleNum]]++;
            ruleNum++;
        }else{
            scanf("%d",&b);
            if(ruleGroup[b]){
                printf("%d\n",(in[b]+size[ruleGroup[b]]+1)%2);
            }else{
                printf("0\n");
            }
        }
    }
    return 0;
}