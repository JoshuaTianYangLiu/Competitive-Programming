#include <bits/stdc++.h>

using namespace std;
#define BFSIZE 20
bool hasOutput=true;
int bfData[BFSIZE];
int datapointer=0;
void printData(){
    for(int i=0; i<BFSIZE; i++){
        if(hasOutput)printf("%d ",bfData[i]);
    }
    if(hasOutput)printf("\n");
    for(int i=0; i<datapointer; i++)if(hasOutput)printf("  ");   //Fix so it works for larger numbers
    if(hasOutput)printf("^");
}
void clear(){
    while(bfData[datapointer]--)if(hasOutput)printf("-");
}
int findEmpty(){
    for(int i=11; i<BFSIZE; i++){
        if(bfData[i]==0)return i;
    }
}
void increment(int a){
    bfData[datapointer]+=a;
    while(a--)if(hasOutput)printf("+");
}
void decrement(int a){
    bfData[datapointer]-=a;
    while(a--)if(hasOutput)printf("-");
}
void moveLeft(int a){   //Move pointer left a times
    for(int i=0; i<a; i++){
        if(hasOutput)printf("<");
    }
    datapointer-=a;
}
void moveRight(int a){   //Move pointer left a times
    for(int i=0; i<a; i++){
        if(hasOutput)printf(">");
    }
    datapointer+=a;
}
void movePointer(int a){    //Move pointer to a
    if(datapointer<a){
        moveRight(a-datapointer);
    }else if(datapointer>a){
        moveLeft(datapointer-a);
    }
}
void move(int a,int b){   //Move and add data from a to b
    movePointer(a);
    if(hasOutput)printf("[");
    while(bfData[datapointer]){
        movePointer(b);
        increment(1);
        movePointer(a);
        decrement(1);
        hasOutput=false;
    }
    hasOutput=true;
    if(hasOutput)printf("]");
}
void copy(int a,int b){ //Copy data from a to b
    int tempSpot = findEmpty();
    move(a,tempSpot);
    movePointer(tempSpot);
    printf("[");
    while(bfData[datapointer]){
        movePointer(a);
        increment(1);
        movePointer(b);
        increment(1);
        movePointer(tempSpot);
        decrement(1);
        hasOutput=false;
    }
    hasOutput=true;
    printf("]");
    bfData[b]=bfData[a];
}
void castToInt(){
    decrement(48);
}
void multiply(int a,int b){ //bfData[a]*=b  multiple the data by b
    int tempSpot=findEmpty();
    movePointer(tempSpot);  //Move to temp spot
    increment(b);           //Increment by multiple
    move(a,tempSpot+1);     //Move data to tempspot
    movePointer(tempSpot);  //Move pointer to tempspot
    printf("[");            //Loop begin
    copy(tempSpot+1,a);     //Copy data from tempspot to a
    movePointer(tempSpot);  //Move pointer to tempspot
    decrement(1);
    printf("]");
    movePointer(tempSpot+1);
    clear();
}

int main() {
    movePointer(0);
    increment(512);
    // move(0,1);
    // copy(1,3);
    // copy(1,0);
    // multiply(1,2);
    return 0;
}
