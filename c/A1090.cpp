#include <cstdio>
#include <math.h>
#include <vector>

using namespace std;

const int maxn=100100;

int n;

double p,r;

struct Node{
    vector<int> child;
}node[maxn];

int level=-1,high_level=-1;
double sales;
int num=0;

void DFS(Node node[maxn],int i){
    level++;
    
    if (node[i].child.size()!=0) {
        for (vector<int>::iterator it=node[i].child.begin(); it!=node[i].child.end(); it++) {
            DFS(node, *it);
        }
    }else{
        if (level>high_level) {
            high_level=level;
            num=1;
        }else if (level==high_level){
            num++;
        }
    }
    
    level--;
    
    return;
}

int main(){
    scanf("%d %lf %lf",&n,&p,&r);
    
    int temp,root=-1;
    
    for (int i=0; i<n; i++) {
        scanf("%d",&temp);
        
        if (temp!=-1) {
            node[temp].child.push_back(i);
        }else{
            root=i;
        }
    }
    
    DFS(node, root);
    
    sales=p*pow((1+r/100.0), high_level);
    
    printf("%.2lf %d\n",sales,num);
    
    return 0;
}