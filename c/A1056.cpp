#include <cstdio>
#include <queue>

using namespace std;

const int maxn=1010;

int n,m;

int mice[maxn];
int rank1[maxn];

queue<int> q1;

int main(){
    scanf("%d %d",&n,&m);
    
    for (int i=0; i<n; i++) {
        scanf("%d",&mice[i]);
    }
    
    int temp;
    
    for (int i=0; i<n; i++) {
        scanf("%d",&temp);
        
        q1.push(temp);
    }
    
    int group,temp1=n;
    
    while (q1.size()!=1) {
        if (temp1%m==0) {
            group=temp1/m;
        }else{
            group=temp1/m+1;
        }
        
        for (int i=0; i<group; i++) {
            
            int k=q1.front();
            
            for (int j=0; j<m; j++) {
                if (i*m+j>=temp1) {
                    break;
                }
                
                int front=q1.front();
                
                if (mice[front]>mice[k]) {
                    k=front;
                }
                
                rank1[front]=group+1;
                q1.pop();
            }
            
            q1.push(k);
        }
        
        temp1=group;
    }
    
    rank1[q1.front()]=1;
    
    for (int i=0; i<n; i++) {
        printf("%d",rank1[i]);
        if (i==n-1) {
            printf("\n");
        }else{
            printf(" ");
        }
    }
}