#include <bits/stdc++.h>

using namespace std;
char in[510][510];
bool checked[510][510];
int n,h,w;
pair<int,int> posHor(){
    pair<int,int> ret={-1,-1};
    for(int i=1; i<=h; i++){
        // printf(":::%d %d %d\n",i,ret.first,ret.second);
        for(int j=1; j<=w; j++){
            if(in[i][j]=='*'&&j>0&&j<=w&&i<=h){
                if(in[i+1][j-1]=='*'){
                    if((j-1<ret.first||ret.first==-1)&&j!=ret.second&&j-1!=ret.second){
                        checked[i+1][j-1]=true;
                        ret.first=j-1;
                    }
                }
                if(in[i+1][j+1]=='*'){
                    if((j+1>ret.second||ret.second==-1)&&j!=ret.first&&j+1!=ret.first){
                        checked[i+1][j+1]=true;
                        ret.second=j+1;
                    }
                }
            }
            // printf("Ret: %d %d\n",ret.first,ret.second);
            if(in[i][j]=='*'&&j>0&&j<=w&&i>0){
                if(in[i-1][j-1]=='*'){
                    // printf("Up Left %d %d %d\n",i,j,ret.second);
                    if((j-1<ret.first||ret.first==-1)&&j!=ret.second&&j-1!=ret.second)ret.first=j-1;
                }
                if(in[i-1][j+1]=='*'){
                    // printf("Up Right %d %d %d\n",i,j,ret.first);
                    if((j+1>ret.second||ret.second==-1)&&j!=ret.first&&j+1!=ret.first)ret.second=j+1;
                }
            }
        }
    }
    return ret;
}
int numOnLine(int i){
    int ret=0;
    for(int j=1; j<=w; j++){
        if(in[i][j]=='*')ret++;
    }
    return ret;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            memset(in,' ',sizeof(in));
            bool a,b,c,d,e,f,g;
            a=b=c=d=e=f=g=false;
            int section=0;
            scanf("%d %d",&h,&w);
            for(int j=1; j<=h; j++){
                scanf("%s",&in[j][1]);
            }
            pair<int,int> col = posHor();
            // printf("::%d %d\n",col.first,col.second);
            if(col.first>col.second&&col.first!=-1&&col.second!=-1){
                col={col.second-1,col.first+1};
            }
            if(col.first==-1&&col.second==-1){
                printf("1");
                continue;
            }
            int topHorLines=-1;
            int j=1;
            for(; j<=h; j++){
                if(col.first!=-1&&in[j][col.first]=='*'){
                    b=true;
                }
                if(col.second!=-1&&in[j][col.second]=='*'){
                    c=true;
                }
                if((col.first!=-1&&in[j][col.first]=='*')||(col.second!=-1&&in[j][col.second]=='*'))break;
                for(int k=0; k<w; k++){
                    if(in[j][k]=='*')a=true;
                }
                // printf("\n");
            }
            while(in[j][col.first]=='*'||in[j][col.second]=='*'){
                j++;
            }
            for(; j<=h; j++){
                if(col.first!=-1&&in[j][col.first]=='*'){
                    e=true;
                }
                if(col.second!=-1&&in[j][col.second]=='*'){
                    f=true;
                }
                if((col.first!=-1&&in[j][col.first]=='*')||(col.second!=-1&&in[j][col.second]=='*'))break;
                for(int k=0; k<w; k++){
                    // printf("%c ",in[j][k]);
                    if(in[j][k]=='*')d=true;
                }
                // printf("::%d\n",j);
                // printf("\n");
            }
            while(in[j][col.first]=='*'||in[j][col.second]=='*'){
                j++;
            }
            for(int k=1; k<=w; k++){
                if(in[j][k]=='*')g=true;
            }
            // printf("%d %d %d %d %d %d %d\n",a,b,c,d,e,f,g);
            if(a&&b&&c&&!d&&e&&f&&g)printf("0");
            else if(a&&!b&&c&&d&&e&&!f&&g)printf("2");
            else if(a&&!b&&c&&d&&!e&&f&&g)printf("3");
            else if(!a&&b&&c&&d&&!e&&f&&!g)printf("4");
            else if(a&&b&&!c&&d&&!e&&f&&g)printf("5");
            else if(a&&b&&!c&&d&&e&&f&&g)printf("6");
            else if(a&&!b&&c&&!d&&!e&&f&&!g)printf("7");
            else if(a&&b&&c&&d&&e&&f&&g)printf("8");
            else if(a&&b&&c&&d&&!e&&f&&g)printf("9");
            else printf("%d %d %d %d %d %d %d\n",a,b,c,d,e,f,g);
        }
        if(t!=0)printf("\n");
    }
    return 0;
}