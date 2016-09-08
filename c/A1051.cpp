#include <cstdio>
#include <stack>

using namespace std;

const int maxn=1010;

int arr[maxn];

stack<int> st;

int n,m,k;

int main(){
    scanf("%d %d %d",&n,&m,&k);
    
    for (int i=0; i<k; i++) {
        while (!st.empty()) {
            st.pop();
        }
        
        for (int j=0; j<m; j++) {
            scanf("%d",&arr[j]);
        }
        
        int current=0;
        
        bool flag=true;
        
        for (int j=1; j<=m; j++) {
            st.push(j);
            
            if (st.size()>n) {
                flag=false;
                break;
            }
            
            while (!st.empty()&&st.top()==arr[current]) {
                st.pop();
                current++;
            }
        }
        
        if (st.empty()==true&&flag==true) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    
    return 0;
}