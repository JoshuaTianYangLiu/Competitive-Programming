#include <bits/stdc++.h>
bool arr[100][100];
bool out[100][100];
bool visited[100];
int cases,nodes;
int ignoreNode;
void dfs2(int a){
  visited[a]=true;
  for(int i=0; i<nodes; i++){
    if(!visited[i]&&arr[a][i]&&i!=ignoreNode){
      dfs2(i);
    }
  }
}
void dfs(int a){
  visited[a]=true;
  out[0][a]=true;
  for(int i=0; i<nodes; i++){
    if(!out[0][i]&&arr[a][i]){
      dfs(i);
    }
  }
}
void println(){
  printf("+");
  for(int i=0; i<nodes*2-1; i++){
    printf("-");
  }
  printf("+\n");
}
int main() {

  scanf("%d",&cases);
  for(int i=0; i<cases; i++){
    memset(arr,false,sizeof(arr));
    memset(out,false,sizeof(out));
    memset(visited,false,sizeof(visited));
    scanf("%d",&nodes);
    for(int n=0; n<nodes; n++){
      for(int m=0; m<nodes; m++){
        scanf("%d",&arr[n][m]);
      }
    }
    for(int j=0; j<nodes; j++){
      ignoreNode=j;
      dfs2(0);
      for(int k=0; k<nodes; k++){
        if(!visited[k])out[j][k]=true;
      }
      memset(visited,false,sizeof(visited));
    }
    dfs(0);
    for(int n=0; n<nodes; n++){
      for(int m=0; m<nodes; m++){
        if(!visited[n]||!visited[m])out[n][m]=false;
      }
    }
    printf("Case %d:\n",i+1);
    println();
    for(int n=0; n<nodes; n++){
      printf("|");
      for(int m=0; m<nodes; m++){
        printf("%s|",out[n][m]?"Y":"N");
      }
      printf("\n");
      println();
    }
  }
}
