#include <bits/stdc++.h>

using namespace std;
struct Node {
    Node(int k){
        key=k;
        size=1;
    }
    int key,size,h=1,freq=1;
    Node *l=NULL,*r=NULL;
};
int h(Node* node){
    if(node==NULL)return 0;
    return node->h;
}
int size(Node* node){
    if(node==NULL)return 0;
    return node->size;
}
int balance(Node* node){
    if(node==NULL)return 0;
    return h(node->l)-h(node->r);
}
Node* rotr(Node *y){
    Node *x = y->l;
    y->l=x->r;
    x->r=y;
    y->size=size(y->l)+size(y->r)+1;
    x->size=size(x->l)+size(x->r)+1;
    y->h=max(h(y->l),h(y->r))+1;
    x->h=max(h(x->l),h(x->r))+1;
    return x;
}
Node* rotl(Node *x){
    Node *y=x->r;
    x->r=y->l;
    y->l=x;
    x->size=size(x->l)+size(x->r)+1;
    y->size=size(y->l)+size(y->r)+1;
    x->h=max(h(x->l),h(x->r))+1;
    y->h=max(h(y->l),h(y->r))+1;
    return y;
}
Node* insert(Node* node,int key){
    if(node==NULL) return new Node(key);
    if(key<node->key)node->l=insert(node->l,key);
    else if(key>node->key)node->r=insert(node->r,key);
    else{
        (node->freq)++;
        node->size=size(node->l)+size(node->r)+node->freq;
        return node;
    }
    //Balance
    node->h=max(h(node->l),h(node->r))+1;
    node->size=size(node->l)+size(node->r)+node->freq;
    if(balance(node)>1&&key!=node->l->key){
        if(key>node->l->key)node->l=rotl(node->l);
        return rotr(node);
    }else if(balance(node)<-1&&key!=node->r->key){
        if(key<node->r->key)node->r=rotr(node->r);
        return rotl(node);
    }
    return node;
}
Node* leftMost(Node* node){
    Node* current=node;
    while(current->l!=NULL)current=current->l;
    return current;
}
Node* deleteVal(Node* node,int key){
    if(node==NULL)return node;
    if(key<node->key)node->l=deleteVal(node->l,key);
    else if(key>node->key)node->r=deleteVal(node->r,key);
    else{
        if(node->freq>1){
            (node->freq)--;
            node->size=size(node->l)+size(node->r)+node->freq;
            return node;
        }
        if(node->l==NULL&&node->r==NULL)node=NULL;
        else if(node->l==NULL||node->r==NULL)*node=node->l?*node->l:*node->r;
        else{
            Node* t=leftMost(node->r);
            node->key=t->key;
            node->r=deleteVal(node->r,t->key);
        }
    }
    if(node==NULL)return node;
    node->h=max(h(node->l),h(node->r))+1;
    node->size=size(node->l)+size(node->r)+node->freq;
    if(balance(node)>1){
        if(balance(node->l)<0)node->l=rotl(node->l);
        return rotr(node);
    }else if(balance(node)<-1){
        if(balance(node->r)>0) node->r=rotr(node->r);
        return rotl(node);
    }
    return node;
}
int valAt(Node* node,int idx){  //Change to fit freq    //REEE Still segfaulting
    // if(node==NULL)return -1;
    if(idx>size(node->l)+node->freq)return valAt(node->r,idx-size(node->l)-node->freq);
    if(idx>size(node->l))return node->key;
    return valAt(node->l,idx);
}
int idxOf(Node* node,int key,int idx=-1){   //Change to fit freq
    if(node==NULL)return -1;
    if(idx==-1)idx=size(node->l);
    if(key==node->key)return idx+1;
    if(key<node->key){
        int lrsize=0,lfreq=0;
        if(node->l!=NULL){
            lrsize=size(node->l->r);
            lfreq=node->l->freq;
        }
        return idxOf(node->l,key,idx-lfreq-lrsize);
    }
    if(key>node->key){
        int rlsize=0,rfreq=0;
        if(node->r!=NULL) rlsize=size(node->r->l);
        return idxOf(node->r,key,idx+rlsize+node->freq);
    }
}
void printTree(Node* root){
    if(root!=NULL){
        // printf("%d %d\n",root->key,root->size);
        printTree(root->l);
        for(int i=0; i<root->freq; i++) printf("%d ",root->key);
        printTree(root->r);
    }
}

int main() {
    Node* root=NULL;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0,a; i<n; i++){
        scanf("%d",&a);
        root=insert(root,a);
    }
    char o;
    int v;
    int ans=0;
    while(m--){
        // scanf("%c %d",&o,&v);
        scanf("%c",&o);
        while(o==' '||o=='\n')scanf("%c",&o);
        scanf("%d",&v);
        // v^=ans;
        // printf("::%c %d\n",o,v);
        if(o=='I')root=insert(root,v);
        if(o=='R'){
            // int ans1=idxOf(root,v);
            // printf("::%d\n",ans1);
            // if(ans1!=-1)
            root=deleteVal(root,v);
        }
        if(o=='S'){
            ans=valAt(root,v);
            printf("%d\n",ans);
        }
        if(o=='L'){
            ans=idxOf(root,v);
            printf("%d\n",ans);
        }
        // printTree(root);
        // printf("\n");
    }
    printTree(root);
    return 0;
}