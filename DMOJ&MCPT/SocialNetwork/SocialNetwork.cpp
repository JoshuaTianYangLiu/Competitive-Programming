#include <bits/stdc++.h>

using namespace std;
char a[25],b[25];
unordered_map<string,int> um;
int bit[200020];
void update(int a,int b){
    for(;a<200020;a+=a&-a)bit[a]+=b;
}
int query(int a){
    int sum=0;
    for(;a;a-=a&-a)sum+=bit[a];
    return sum;
}
int query(int a,int b){
    return query(b)-query(a-1);
}
int ufds[200020],rnk[200020];
int fs(int n){return ufds[n]==n?n:fs(ufds[n]);}
int ss(int a,int b){return fs(a)==fs(b);}
void uset(int a,int b){
    if(!ss(a,b)){
        a=fs(a);b=fs(b);
        if(rnk[a]>rnk[b]){
            ufds[b]=a;
            update(a,query(b,b));
            update(b,-query(b,b));
            printf("%d\n",query(a,a));
        }else{
            ufds[a]=b;
            update(b,query(a,a));
            update(a,-query(a,a));
            printf("%d\n",query(b,b));
            if(rnk[a]==rnk[b])rnk[b]++;
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int count=1;
    for(int i=1; i<=2*n; i++){
        ufds[i]=i;
        update(i,1);
    }
    for(int i=1; i<=n; i++){
        scanf("%s %s",a,b);
        if(!um[a])um[a]=count++;
        if(!um[b])um[b]=count++;
        uset(um[a],um[b]);
    }

    return 0;
}