#include <bits/stdc++.h>

using namespace std;
struct g{int a,b,c,type;};
g np[200015];
bool cmp(g a,g b){return a.c<b.c;}
int n[100005];
int m[100005];
int findSetN(int i) { return (n[i] == i) ? i : (n[i] = findSetN(n[i])); }
bool isSameSetN(int i, int j) { return findSetN(i) == findSetN(j);}
void unionSetN(int i, int j) {
    if (!isSameSetN(i, j)) { // if from different set
        n[findSetN(i)]= findSetN(j);
    }
} 
int findSetM(int i) { return (m[i] == i) ? i : (m[i] = findSetM(m[i])); }
bool isSameSetM(int i, int j) { return findSetM(i) == findSetM(j);}
void unionSetM(int i, int j) {
    if (!isSameSetM(i, j)) { // if from different set
        m[findSetM(i)]= findSetM(j);
    }
} 
int main() {
    long long nN,mN;
    int p,q;
    scanf("%lld %lld %d %d",&nN,&mN,&p,&q);
    for(int i=0,a,b,c; i<p; i++){
        scanf("%d %d %d",&a,&b,&c);
        np[i]={a,b,c,0};
    }
    for(int i=p,a,b,c; i<q+p; i++){
        scanf("%d %d %d",&a,&b,&c);
        np[i]={a,b,c,1};
    }
    for(int i=0; i<=max(nN,mN); i++)n[i]=i,m[i]=i;
    sort(begin(np),begin(np)+p+q,cmp);
    long long l=0,w=0;
    long long ans=0;
    for(int i=0; i<q+p; i++){
        if(np[i].type){
            //p
            if(!isSameSetN(np[i].a,np[i].b)){
                ans+=l*np[i].c;
                unionSetN(np[i].a,np[i].b);
                w++;
            }else{
                ans+=mN*np[i].c;
            }
        }else{
            //q
            if(!isSameSetM(np[i].a,np[i].b)){
                ans+=w*np[i].c;
                unionSetM(np[i].a,np[i].b);
                l++;
            }else{
                ans+=nN*np[i].c;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
