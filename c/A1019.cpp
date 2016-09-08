#include <cstdio>
#include <vector>

using namespace std;

int a,b,flag=0;

vector<int> s1;

int main(){
    scanf("%d %d",&a,&b);
    
    while (a/b!=0) {
        s1.push_back(a%b);
        a=a/b;
    }
    
    s1.push_back(a);
    
    for (int i=0,j=(int)s1.size()-1;; i++) {
        if (i>=j) {
            break;
        }
        
        if (s1[i]!=s1[j]) {
            flag=1;
            break;
        }
        
        j--;
    }
    
    if (flag==0) {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    
    for (int i=(int)s1.size()-1; i>=0; i--) {
        printf("%d",s1[i]);
        if (i!=0) {
            printf(" ");
        }else{
            printf("\n");
        }
    }
    
    return 0;
}