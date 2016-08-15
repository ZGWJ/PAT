#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn=150;

struct Node{
    vector<int> child;
}node[maxn];

int n,m;

bool isroot[maxn];

int level_num[maxn];

int level=-1,high_level=-1;

void DFS(Node node[maxn],int root){
    level++;
    
    if (node[root].child.size()!=0) {
        for (vector<int>::iterator it=node[root].child.begin(); it!=node[root].child.end(); it++) {
            DFS(node, *it);
        }
    }else{
        level_num[level]++;
    }
    
    if (level>high_level) {
        high_level=level;
    }
    
    level--;
    
    return;
}

int main(){
    memset(isroot, -1, sizeof(isroot));
    memset(level_num, 0, sizeof(level_num));
    
    scanf("%d %d",&n,&m);
    
    int id,num,root;
    
    for (int i=0; i<m; i++) {
        scanf("%d %d",&id,&num);
        
        int temp;
        
        for (int j=0; j<num; j++) {
            scanf("%d",&temp);
            
            node[id].child.push_back(temp);
            
            isroot[temp]=false;
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (isroot[i]==true) {
            root=i;
            break;
        }
    }
    
    DFS(node, root);
    
    for (int i=0; i<=high_level; i++) {
        printf("%d",level_num[i]);
        
        if (i!=high_level) {
            printf(" ");
        }else{
            printf("\n");
        }
    }
    
    return 0;
}