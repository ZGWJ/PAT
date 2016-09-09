#include <cstdio>
#include <vector>

const int maxn=100100;

using namespace std;

int count1[maxn]={0};

vector<int> s1;

int n;

int main(){
    scanf("%d",&n);
    
    int a;
    
    for (int i=0; i<n; i++) {
        scanf("%d",&a);
        
        if (count1[a]==0) {
            s1.push_back(a);
        }
        
        count1[a]++;
    }
    
    for (vector<int>::iterator it=s1.begin();it!=s1.end(); it++) {
        if (count1[*it]==1) {
            printf("%d\n",*it);
            
            return 0;
        }
    }
    
    printf("None\n");
    
    return 0;
}