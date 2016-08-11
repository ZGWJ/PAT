#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn=50;

int n;

struct Node{
    int data;
    Node* lchild;
    Node* rchild;
};

int pre[maxn]={0},in[maxn]={0},post[maxn]={0};

Node* create(int preL,int preR,int inL,int inR){
    if (preL>preR) {
        return NULL;
    }
    
    Node* root=new Node;
    
    root->data=pre[preL];
    
    int k;
    
    for (k=inL; k<=inR; k++) {
        if (in[k]==pre[preL]) {
            break;
        }
    }
    
    int numleft=k-inL;
    
    root->lchild=create(preL+1, preL+numleft, inL, k-1);
    root->rchild=create(preL+numleft+1, preR, k+1, inR);
    
    return root;
};

int num1=0;

void postorder(Node* root){
    if (root==NULL) {
        return;
    }
    
    postorder(root->lchild);
    postorder(root->rchild);
    
    printf("%d",root->data);
    num1++;
    if (num1<n) {
        printf(" ");
    }
}

int main(){
    int num;
    int precount=0,incount=0;
    
    stack<int> st;
    
    
    scanf("%d",&n);
    
    char str[5];
    
    for (int i=0; i<2*n; i++) {
        
        scanf("%s",str);
        
        if (strcmp(str, "Push")==0) {
            scanf("%d",&num);
            pre[precount++]=num;
            st.push(num);
        }else{
            num=st.top();
            st.pop();
            in[incount++]=num;
        }
        
    }
    
    Node* root=create(0, n-1, 0, n-1);
    
    postorder(root);
    
    return 0;
}