#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=100100;

int n,m;

int d[maxn],dis[maxn];

int main(){
    int a,b,dist1=0,dist2=0,total=0;
    
    dis[0]=0;
    
    scanf("%d",&n);
    
    for (int i=1; i<=n; i++) {
        scanf("%d",&d[i]);
        total+=d[i];
        dis[i]=total;
    }
    
    scanf("%d",&m);
    
    for (int i=0; i<m; i++) {
        scanf("%d %d",&a,&b);
        
        if (a>b) {
            swap(a,b);
        }
        
        dist1=dis[b-1]-dis[a-1];
        
        dist2=total-dist1;
        
        if (dist1>=dist2) {
            printf("%d\n",dist2);
        }else{
            printf("%d\n",dist1);
        }
        
        dist1=dist2=0;
    }
    
    return 0;
}