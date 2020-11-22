#include <bits/stdc++.h>

using namespace std;
int in[1010][1010];
int psa[1010][1010];
int median[1010];
int n;
int medianOfMedian(){
    for(int i=1; i<=n; i++){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int j=1; j<=n; j++){
            pq.push(psa[j][i]);
        }
        for(int i=1; i<(n+1)/2; i++){
            pq.pop();
        }
        median[i]=pq.top();
    }
    priority_queue<int,vector<int>,greater<int>> ppq;
    for(int i=1; i<=n; i++){
        ppq.push(median[i]);
    }
    for(int i=1; i<(n+1)/2; i++){
        ppq.pop();
    }
    return ppq.top();
}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=2; j<=n; j++){
            scanf("%d",&in[i][j]);
            psa[i][j]=psa[i][j-1]+in[i][j];
        }
    }
    int change = medianOfMedian();
    printf("YES\n");
    for(int i=1; i<=n; i++){
        printf("%d ",-change);
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         printf("%d ",psa[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}