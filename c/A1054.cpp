#include <cstdio>
#include <map>

using namespace std;

map<int,int> P;

int main(){
    int m,n,temp;
    
    scanf("%d %d",&m,&n);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d",&temp);
            
            if (P.find(temp)!=P.end()) {
                P[temp]++;
            }else{
                P[temp]=1;
            }
        }
    }
    
    int k=0,max=0;
    
    for (map<int,int>::iterator it=P.begin(); it!=P.end(); it++) {
        if (it->second>max) {
            k=it->first;
            max=it->second;
        }
    }
    
    printf("%d\n",k);
    
    return 0;
}