#include <bits/stdc++.h>

using namespace std;
char a[110],b[110];
bool taken[110][2];
int main() {
    scanf("%s\n%s",a,b);
    int n=strlen(a);
    int ans=0;
    for(int i=0; i<n; i++){
        if(a[i]=='0'&&b[i]=='0'&&!taken[i][0]&&!taken[i][1]){
            // tl bl tr br
            if(i&&!taken[i-1][0]&&a[i-1]=='0'){
                taken[i-1][0]=true;
                taken[i][0]=true;
                taken[i][1]=true;
                ans++;
                continue;
            }
            if(i&&!taken[i-1][1]&&b[i-1]=='0'){
                taken[i-1][1]=true;
                taken[i][0]=true;
                taken[i][1]=true;
                ans++;
                continue;
            }
            if(i<n-1&&!taken[i+1][1]&&b[i+1]=='0'){
                taken[i+1][1]=true;
                taken[i][0]=true;
                taken[i][1]=true;
                ans++;
                continue;
            }
            if(i<n-1&&!taken[i+1][0]&&a[i+1]=='0'){
                taken[i+1][0]=true;
                taken[i][0]=true;
                taken[i][1]=true;
                ans++;
                continue;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}