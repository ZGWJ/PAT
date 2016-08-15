#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn=150;

int n,m;

struct Node{
    vector<int> child;
}node[maxn];

bool isroot[maxn]={true};
int hashtable[maxn];

int level=0;

void DFS(Node node[maxn],int root){
    level++;
    
    hashtable[level]++;
    if (node[root].child.size()!=0) {
        for (vector<int>::iterator it=node[root].child.begin(); it!=node[root].child.end(); it++) {
            DFS(node, *it);
        }
    }
    
    level--;
    return;
}

int main(){
    memset(isroot, -1, sizeof(isroot));
    memset(hashtable, 0, sizeof(hashtable));
    
    scanf("%d %d",&n,&m);
    
    int temp,num,root,high_num=0,generation=0;
    
    for (int i=0; i<m; i++) {
        scanf("%d %d",&temp,&num);
        int tempchild;
        for (int j=0; j<num; j++) {
            scanf("%d",&tempchild);
            node[temp].child.push_back(tempchild);
            isroot[tempchild]=false;
        }
    }

    for (int i=1; i<=n; i++) {
        if (isroot[i]==true) {
            root=i;
            break;
        }
    }
    
    DFS(node, root);
    
    for (int i=1; i<maxn; i++) {
        if (hashtable[i]>high_num) {
            high_num=hashtable[i];
            generation=i;
        }
    }
    
    printf("%d %d\n",high_num,generation);
    
    return 0;
}