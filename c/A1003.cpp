#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXV=510;
const int INF=1000000000;

//顶点数n 边数m st、ed起点、终点
//G邻接矩阵 weight 点权
//d[]最短距离 w[]最大点权之和 num[]最短路径条数
int n,m,st,ed,G[MAXV][MAXV],weight[MAXV];
int d[MAXV],w[MAXV],num[MAXV];
bool vis[MAXV]={false};//是否访问

void Dijkstra(int s){
    fill(d, d+MAXV, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    
    for (int i=0; i<n; i++) {
        int u=-1,MIN=INF;
        for (int j=0; j<n; j++) {
            if (vis[j]==false&&d[j]<MIN) {
                u=j;
                MIN=d[j];
            }
        }
        if (u==-1) {
            return;
        }
        vis[u]=true;
        for (int v=0; v<n; v++) {
            if (vis[v]==false&&G[u][v]!=INF) {
                if (d[u]+G[u][v]<d[v]) {
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }else if(d[u]+G[u][v]==d[v]){
                    if(w[u]+weight[v]>w[v]){
                        w[v]=w[u]+weight[v];
                    }
                    num[v]+=num[u];
                }
            }
        }
    }
}

int main(){
    fill(G[0], G[0]+MAXV*MAXV, INF);
    
    int x,y,z;
    scanf("%d %d %d %d",&n,&m,&st,&ed);
    
    for (int i=0; i<n; i++) {
        scanf("%d",&weight[i]);
    }
    
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&x,&y,&z);
        G[x][y]=z;
        G[y][x]=G[x][y];
    }
    
    Dijkstra(st);
    printf("%d %d\n",num[ed],w[ed]);
}