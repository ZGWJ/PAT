#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=1010;

int hobby[maxn]={0};

int father[maxn];

int root[maxn]={0};

int findfather(int k){
    while (father[k]!=k) {
        k=father[k];
    }
    
    return k;
}

void Union(int a,int b){
    int faA=findfather(a);
    int faB=findfather(b);
    
    if (faA!=faB) {
        father[faB]=faA;
    }
}

bool cmp(int a,int b){
    return a>b;
}

int main(){
    for (int i=1; i<maxn; i++) {
        father[i]=i;
    }
    
    int n,temp,h;
    scanf("%d",&n);
    
    for (int i=1; i<=n; i++) {
        scanf("%d:",&temp);
        for (int j=0; j<temp; j++) {
            scanf("%d",&h);
            
            if (hobby[h]==0) {
                hobby[h]=i;
            }
            
            Union(i,findfather(hobby[h]));
        }
    }
    
    for (int i=1; i<=n; i++) {
        root[findfather(i)]++;
    }
    
    int ans=0;
    
    for (int i=1; i<=n; i++) {
        if (root[i]!=0) {
            ans++;
        }
    }
    
    sort(root+1,root+1+n,cmp);
    
    printf("%d\n",ans);
    
    for (int i=1; i<=ans; i++) {
        printf("%d",root[i]);
        if (i!=ans) {
            printf(" ");
        }
    }
    
    return 0;
}