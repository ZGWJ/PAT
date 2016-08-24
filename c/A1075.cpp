#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=10100;

struct People{
    int order;
    int ID;
    int num_perfect=0;
    int pass=0;
    int total=0;
    int grade[10]={-1};
}people[maxn];

int problems[10];

bool cmp(People a,People b){
    if (a.total==b.total) {
        if (a.num_perfect==b.num_perfect) {
            return a.ID<b.ID;
        }
        return a.num_perfect>b.num_perfect;
    }
    return a.total>b.total;
}

void init(){
    for (int i=0; i<maxn; i++) {
        people[i].num_perfect=people[i].pass=people[i].total=0;
        for (int j=0; j<10; j++) {
            people[i].grade[j]=-1;
        }
    }
}

int main(){
    int n,k,m;
    int a,b,c;
    
    init();
    
    scanf("%d %d %d",&n,&k,&m);
    
    for (int i=1; i<=k; i++) {
        scanf("%d",&problems[i]);
    }
    
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&a,&b,&c);
        
        people[a].ID=a;
        
        if (c>-1) {
            if (c==problems[b]&&people[a].grade[b]!=problems[b]) {
                people[a].num_perfect++;
            }
            people[a].pass++;
            
        }else{
            if (people[a].grade[b]==-1) {
                people[a].grade[b]=0;
            }
        }
        
        if (c>people[a].grade[b]) {
            people[a].grade[b]=c;
        }
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (people[i].grade[j]>-1) {
                people[i].total+=people[i].grade[j];
            }
        }
    }
    
    sort(people+1, people+1+n,cmp);
    
    people[1].order=1;
    
    for (int i=2; i<=n; i++) {
        if (people[i].total==people[i-1].total) {
            people[i].order=people[i-1].order;
        }else{
            people[i].order=i;
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (people[i].pass>0) {
            printf("%d %05d %d ",people[i].order,people[i].ID,people[i].total);
            for (int j=1; j<=k; j++) {
                if (people[i].grade[j]!=-1) {
                    printf("%d",people[i].grade[j]);
                }else{
                    printf("-");
                }
                
                if (j!=k) {
                    printf(" ");
                }else{
                    printf("\n");
                }
            }
        }
    }
}