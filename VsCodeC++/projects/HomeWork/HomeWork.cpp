#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
pair<double,int> in[1000001];
bool hw[1000001];
int main() {
    for(int a=0; a<10; a++){
        memset(hw,false,sizeof(hw));
        int size;
        scanf("%d",&size);
        priority_queue<pair<int,double>,vector<pair<int,double>>,greater<pair<int,double>>> pq;
        for(int i=0; i<size; i++){
            int b;
            double c;
            scanf("%d %lf",&b,&c);
            pq.push({b,100-c});
        }
        double out=0;
        int day=1;
        while(!pq.empty()){
            pair<int,double> p=pq.top();
            pq.pop();
            if(p.first>=day){
                out+=100-p.second;
                day++;
            }
        }
        printf("%.4f\n",out);
    }

}