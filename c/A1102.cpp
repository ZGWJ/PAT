#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn=15;

bool vis[maxn]={false};

int n;

int num_in=0;

struct Node{
    int lchild;
    int rchild;
}Node[maxn];

int str2num(char char1){
    int int1=-2;
    
    if (char1>='0'&&char1<='9') {
        int1=char1-'0';
    }else if (char1=='-'){
        int1=-1;
    }
    
    return int1;
}

void postorder(int root){
    if (Node[root].lchild!=-1) {
        int root1=Node[root].lchild;
        postorder(root1);
    }
    if (Node[root].rchild!=-1) {
        int root2=Node[root].rchild;
        postorder(root2);
    }
    
    int temp;
    temp=Node[root].lchild;
    Node[root].lchild=Node[root].rchild;
    Node[root].rchild=temp;
    
    return;
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    
    int num=0;
    
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        
        printf("%d",now);
        num++;
        if (num<n) {
            printf(" ");
        }else{
            printf("\n");
        }
        
        if (Node[now].lchild!=-1) {
            q.push(Node[now].lchild);
        }
        if (Node[now].rchild!=-1) {
            q.push(Node[now].rchild);
        }
    }

}

void inorder(int root){
    
    if (Node[root].lchild!=-1) {
        int root1=Node[root].lchild;
        inorder(root1);
    }
    
    printf("%d",root);
    num_in++;
    if (num_in<n) {
        printf(" ");
    }
    
    if (Node[root].rchild!=-1) {
        int root2=Node[root].rchild;
        inorder(root2);
    }
    
    return;
}

int main(){
    char char1,char2;
    int root=-1;
    
    scanf("%d",&n);
    getchar();
    
    for (int i=0; i<n; i++) {
        scanf("%c",&char1);
        getchar();
        scanf("%c",&char2);
        getchar();
        Node[i].lchild=str2num(char1);
        Node[i].rchild=str2num(char2);
        
        if (Node[i].lchild!=-1) {
            vis[Node[i].lchild]=true;
        }
        if (Node[i].rchild!=-1) {
            vis[Node[i].rchild]=true;
        }
    }
    
    for (int i=0; i<maxn; i++) {
        if (vis[i]==false) {
            root=i;
            break;
        }
    }
    
    postorder(root);
    
    BFS(root);
    
    inorder(root);
    
    return 0;
}