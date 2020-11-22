#include <bits/stdc++.h>

using namespace std;
const int MM=1e9+7;
pair<int,int> inst[100010];
vector<string> names;
map<string,int> nameToInst;
map<string,int> nameToEnd;
map<string,pair<int,int>> nameToFunc;
stack<string> funcStack;
char in[20];
char funcName[20];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,v;
        scanf("%d",&n);
        int cnt=0;
        for(int i=0; i<n; i++){
            scanf("%s",in);
            if(in[0]=='A'){
                scanf("%d",&v);
                inst[i]={0,v};
            }
            if(in[0]=='S'){
                scanf("%d",&v);
                inst[i]={1,v};
            }
            if(in[0]=='M'){
                scanf("%d",&v);
                inst[i]={2,v};
            }
            if(in[0]=='F'){
                scanf("%s",funcName);
                inst[i]={3,names.size()};
                names.push_back(funcName);
                nameToInst[funcName]=i;
                funcStack.push(funcName);
            }
            if(in[0]=='E'){
                inst[i]={4,-1};
                string na = funcStack.top();funcStack.pop();
                nameToEnd[na]=i;
            }
            if(in[0]=='C'){
                scanf("%s",funcName);
                inst[i]={5,names.size()};
                names.push_back(funcName);
            }
        }
        stack<int> theStack;
        int funcPointer=0;
        long long amount=0;
        //Check when END is at the end
        //Empty functions
        while(funcPointer<n){
            if(inst[funcPointer].first==0){
                //Add
                amount+=inst[funcPointer++].second;
                amount%=MM;
            }else if(inst[funcPointer].first==1){
                amount-=inst[funcPointer++].second;
                amount%=MM;
                amount+=MM;
                amount%=MM;
            }else if(inst[funcPointer].first==2){
                amount*=inst[funcPointer++].second;
                amount%=MM;
            }else if(inst[funcPointer].first==3){
                funcPointer=nameToEnd[names[inst[funcPointer].second]]+1;
            }else if(inst[funcPointer].first==4){
                funcPointer=theStack.top()+1;
                theStack.pop();
            }else if(inst[funcPointer].first==5){
                theStack.push(funcPointer);
                funcPointer=nameToInst[names[inst[funcPointer].second]]+1;
            }
            // printf("%d\n",funcPointer);
            // printf("%lld\n",amount);
        }
        printf("%lld\n",amount);
    }
    return 0;
}