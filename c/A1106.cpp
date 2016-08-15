#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn=100100;

int n;

double p,r;

struct Node{
    vector<int> child;
}node[maxn];

int level=-1,low_level=100200,num=0;

void DFS(Node node[maxn],int root){
    level++;
    
    if (node[root].child.size()!=0) {
        for (vector<int>::iterator it=node[root].child.begin(); it!=node[root].child.end(); it++) {
            DFS(node, *it);
        }
    }else{
        if (level<low_level) {
            low_level=level;
            num=1;
        }else if (level==low_level){
            num++;
        }
    }
    
    level--;
}

int main(){
    scanf("%d %lf %lf",&n,&p,&r);
    
    int temp_num,temp;
    
    double lowprice;
    
    for (int i=0; i<n; i++) {
        scanf("%d",&temp_num);
        
        if (temp_num!=0) {
            for (int j=0; j<temp_num; j++) {
                scanf("%d",&temp);
                node[i].child.push_back(temp);
            }
        }
    }
    
    DFS(node, 0);
    
    lowprice=p*pow((1+r/100.0), low_level);
    
    printf("%.4lf %d\n",lowprice,num);
    
    return 0;
}