#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn=150;

int n;

struct Node{
    int data;
    int lchild,rchild;
}node[maxn];

int num[maxn];

vector<int> id;

queue<int> qu;

void inOrder(int root,vector<int> &vi){
    if (node[root].lchild!=-1) {
        inOrder(node[root].lchild,vi);
    }
    vi.push_back(root);
    if (node[root].rchild!=-1) {
        inOrder(node[root].rchild, vi);
    }
    
    return;
};

int count1=0;

void BFS(int root){
    qu.push(root);
    
    while (!qu.empty()) {
        int now=qu.front();
        qu.pop();
        printf("%d",node[now].data);
        count1++;
        if (count1<n) {
            printf(" ");
        }else{
            printf("\n");
        }
        if (node[now].lchild!=-1) {
            qu.push(node[now].lchild);
        }
        if (node[now].rchild!=-1) {
            qu.push(node[now].rchild);
        }
    }
}

int main(){
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        scanf("%d %d",&node[i].lchild,&node[i].rchild);
    }
    
    for (int i=0; i<n; i++) {
        scanf("%d",&num[i]);
    }
    
    sort(num, num+n);
    
    inOrder(0,id);
    
    for (int i=0; i<id.size(); i++) {
        node[id[i]].data=num[i];
    }
    
    BFS(0);
    
    return 0;
}