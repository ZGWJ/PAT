#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=150;

int n,m,s;

struct Node{
    vector<int> child;
    int weight;
}node[maxn];


vector<int> temp;

vector<int> ans[maxn];

int count_temp=0;

int sum=0;

bool cmp(int a,int b){
    return node[a].weight>node[b].weight;
}

void DFS(Node node[maxn],int root){
    sum+=node[root].weight;
    
    temp.push_back(node[root].weight);
    
    if (sum<=s) {
        
        if (node[root].child.size()!=0) {
            for (vector<int>::iterator it=node[root].child.begin(); it!=node[root].child.end(); it++) {
                DFS(node,*it);
            }
        }else{
            if (sum==s) {
                for (vector<int>::iterator it=temp.begin(); it!=temp.end(); it++) {
                    ans[count_temp].push_back(*it);
                }
                
                count_temp++;
            }
        }
    }
    
    sum-=node[root].weight;
    
    temp.pop_back();
    
    return;
}

int main(){
    scanf("%d %d %d",&n,&m,&s);
    
    for (int i=0; i<n; i++) {
        scanf("%d",&node[i].weight);
    }
    
    int id,temp_num;
    for (int i=0; i<m; i++) {
        scanf("%d %d",&id,&temp_num);
        
        int temp;
        for (int j=0; j<temp_num; j++) {
            scanf("%d",&temp);
            node[id].child.push_back(temp);
        }
        
        sort(node[id].child.begin(), node[id].child.end(), cmp);
    }
    
    DFS(node, 0);
    
    for (int i=0; i<=count_temp; i++) {
        for (int j=0; j<ans[i].size(); j++) {
            printf("%d",ans[i][j]);
            if (j!=(ans[i].size()-1)) {
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    
    return 0;
}