#include <cstdio>
#include <cstring>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn=100100;

int n;

double p,r;

struct Node{
    int data=0;
    vector<int> child;
}node[maxn];

int level=-1;
double sales;

void DFS(Node node[maxn],int i){
    level++;
    
    if (!node[i].child.empty()) {
        for (vector<int>::iterator it=node[i].child.begin(); it!=node[i].child.end(); it++) {
            DFS(node, *it);
        }
    }else{
        sales+=node[i].data*p*pow((1+r/100.0), level);
    }
    
    level--;
    
    return;
}

int main(){
    scanf("%d %lf %lf",&n,&p,&r);
    
    int tempnum=0;
    
    for (int i=0; i<n; i++) {
        
        scanf("%d",&tempnum);
        
        int temp;
        
        if (tempnum!=0) {
            for (int j=0; j<tempnum; j++) {
                scanf("%d",&temp);
                
                node[i].child.push_back(temp);
            }
        }else{
            scanf("%d",&temp);
            
            node[i].data=temp;
        }
        
    }
    
    DFS(node, 0);
    
    printf("%.1lf\n",sales);
    
    return 0;
}