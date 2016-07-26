//采用BFS，考虑到了在路程较短的情况下一些节点在已被visit的情况下可再次被visit
//且可继续深入的情况，但程序仍有问题。

#include <cstdio>
#include <vector>

using namespace std;

const int N=1111;

vector<int> G[N];
vector<int> T[N];

bool vis[N]={false};
int levelofN[N]={1111};

int num=-1;
int level=-1;

void DFS(int K,int L){
    
    //遇之前则返回
    if (vis[K]==true) {
        if (level<levelofN[K]-1) {
            num--;
        }else{
            return;
        }
    }
    
    num++;
    level++;
    vis[K]=true;
    
    levelofN[K]=level;
    
    if (level<L) {
        for (int i=0;i<T[K].size(); i++) {
            DFS(T[K][i], L);
        }
    }

    level--;
    return;
}

int main(){
    int N,L;
    scanf("%d %d",&N,&L);
    
    for (int i=1; i<=N; i++) {//创建邻接表
        int num;
        scanf("%d",&num);
        for (int j=0; j<num; j++) {
            int temp;
            scanf("%d",&temp);
            G[i].push_back(temp);
        }
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=0; j<G[i].size(); j++) {
            T[G[i][j]].push_back(i);
        }
    }
    
    int K;
    int node;
    scanf("%d",&K);
    for (int i=0; i<K; i++) {
        scanf("%d",&node);
        DFS(node, L);
        
        printf("%d\n",num);
        num=-1;
        level=-1;
        for (int j=0; j<N; j++) {
            vis[j]=false;
            levelofN[j]=1111;
        }
    }
}

//BFS

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXV=1010;

struct Node{
    int ID;
    int layer;
};

vector<Node> Adj[MAXV];
bool inq[MAXV]={false};

int BFS(int s,int L){
    int numForward=0;
    queue<Node> q;
    
    Node start;
    
    start.ID=s;
    start.layer=0;
    
    q.push(start);
    inq[start.ID]=true;
    
    while (!q.empty()) {
        Node topNode=q.front();
        q.pop();
        int u=topNode.ID;
        
        for (int i=0; i<Adj[u].size(); i++) {
            Node next=Adj[u][i];
            next.layer=topNode.layer+1;
            
            if (inq[next.ID]==false&&next.layer<=L) {
                q.push(next);
                inq[next.ID]=true;
                numForward++;
            }
        }
    }
    
    return numForward;
}

int main(){
    Node user;
    int n,L,numFollow,idFollow;
    scanf("%d %d",&n,&L);
    
    for (int i=1; i<=n; i++) {
        user.ID=i;
        scanf("%d",&numFollow);
        
        for (int j=0; j<numFollow; j++) {
            scanf("%d",&idFollow);
            Adj[idFollow].push_back(user);
        }
    }
    
    int numQuery,s;
    scanf("%d",&numQuery);
    
    for (int i=0; i<numQuery; i++) {
        memset(inq, false, sizeof(inq));
        scanf("%d",&s);
        int numForward=BFS(s, L);
        printf("%d\n",numForward);
    }
}









