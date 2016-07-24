#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=11111;

vector<int> G[N];

int father[N];

bool isBoot[N];

void init(int n){
    for (int i=1; i<=n; i++) {
        father[i]=i;
    }
}

int findFather(int x){
    int a=x;
    while (x!=father[x]) {
        x=father[x];
    }
    
    while (a!=father[a]) {
        int z=a;
        a=father[a];
        father[z]=x;
    }
    
    return x;
}

void Union(int a,int b){
    int faA=findFather(a);
    int faB=findFather(b);
    
    if (faA!=faB) {
        father[faA]=faB;
    }
}

int CalBlock(int n){
    int Block=0;
    
    for (int i=1; i<=n; i++) {
        isBoot[findFather(i)]=true;
    }
    
    for (int i=1; i<=n; i++) {
        Block+=isBoot[i];
    }
    
    return Block;
}

int maxH=0;//最大高度
vector<int> temp,Ans;

void DFS(int u,int Height,int pre){
    if (Height>maxH) {
        temp.clear();
        temp.push_back(u);
        maxH=Height;
    }else if (Height==maxH){
        temp.push_back(u);
    }
    
    for (int i=0; i<G[u].size(); i++) {
        if (G[u][i]==pre) {
            continue;
        }
        DFS(G[u][i], Height+1, u);
    }
}

int main(){
    int n;
    int a,b;
    
    scanf("%d",&n);
    
    init(n);
    
    for (int i=1; i<n; i++) {
        
        scanf("%d %d",&a,&b);
        
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a, b);
    }
    
    int Block=CalBlock(n);
    
    if (Block!=1) {
        printf("Error: %d components\n",Block);
    }else{
        DFS(1, 1, -1);
        Ans=temp;
        DFS(Ans[0], 1, -1);
        for (int i=0; i<temp.size(); i++) {
            Ans.push_back(temp[i]);
        }
        
        sort(Ans.begin(), Ans.end());
        
        printf("%d\n",Ans[0]);
        
        for (int i=1; i<Ans.size(); i++) {
            if (Ans[i]!=Ans[i-1]) {
                printf("%d\n",Ans[i]);
            }
        }
    }
    
    return 0;
}