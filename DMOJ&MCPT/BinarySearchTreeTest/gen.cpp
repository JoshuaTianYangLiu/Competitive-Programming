#include <bits/stdc++.h>

using namespace std;
vector<int> tree;
int main() {
    freopen("data.in","w",stdout);
    srand(time(0));
    // int n=rand()%10+10,m=rand()%50+50;
    int n=100000,m=500000;
    printf("%d %d\n",n,m);
    for(int i=0; i<n; i++){
        int a=rand()%100;
        tree.push_back(a);
        printf("%d ",a);
    }
    printf("\n");
    sort(tree.begin(),tree.end());
    int size=n;
    for(int i=0; i<m; i++){
        int op=rand()%4;
        if(op==0){
            int a= rand()%100;
            printf("I %d\n",a);
            size++;
        }else if(op==1){
            int a=rand()%100;
            printf("R %d\n",a);
            size--;
        }else if(op==2){
            if(size<0){
                i--;
                continue;
            }
            int a=rand()%size+1;
            printf("S %d\n",a);
        }else{
            int a=rand()%100;
            printf("L %d\n",a);
        }
    }
    fclose(stdout);
    return 0;
}