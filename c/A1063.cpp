#include <cstdio>
#include <set>

using namespace std;

const int maxn=51;

set<int> st[maxn];

int n;

void compare(int x,int y){
    int totalNum=(int)st[y].size(),sameNum=0;
    
    for (set<int>::iterator it=st[x].begin(); it!=st[x].end(); it++) {
        if (st[y].find(*it)!=st[y].end()) {
            sameNum++;
        }else{
            totalNum++;
        }
    }
    
    printf("%.1f%%\n",sameNum*100.0/totalNum);
}

int main(){
    scanf("%d",&n);
    int x,y;
    for (int i=1; i<=n; i++) {
        scanf("%d",&x);
        
        for (int j=0; j<x; j++) {
            scanf("%d",&y);
            
            st[i].insert(y);
        }
    }
    
    int k,p,q;
    scanf("%d",&k);
    
    for (int i=0; i<k; i++) {
        scanf("%d %d",&p,&q);
        
        compare(p, q);
    }
    
    return 0;
}