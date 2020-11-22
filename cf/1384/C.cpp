#include <bits/stdc++.h>

using namespace std;
char A[100010],B[100010];
int table[21][21];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(table,0,sizeof(table));
        int n;
        scanf("%d",&n);
        scanf("%s",A);
        scanf("%s",B);
        bool flag=false;
        for(int i=0; i<n; i++){
            table[A[i]-'a'][B[i]-'a']++;
            if(A[i]>B[i]){
                // printf("%c %c\n",A[i],B[i]);
                flag=true;
            }
        }
        if(flag){
            printf("-1\n");
            continue;
        }
        int ans=0;
        for(int i=0; i<20; i++){
            bool check=true;
            if(table[i][i+1]!=0){
                ans++;
                check=false;
            }
            for(int j=i+1; j<20; j++){
                if(j!=i+1&&table[i][j]!=0&&table[i+1][j]!=0&&check){
                    // printf("%c %c\n",i+'a',j+'a');
                    ans++;
                    check=false;
                }
                table[i+1][j]+=table[i][j];
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}