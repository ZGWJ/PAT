#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=1111;

int n;
int index1=0;
int number[maxn],CBT[maxn];

void inOrder(int root){
    if (root>n) {
        return;
    }
    inOrder(root*2);
    CBT[root]=number[index1++];
    inOrder(root*2+1);
}

int main(){
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        scanf("%d",&number[i]);
    }
    
    sort(number, number+n);
    
    inOrder(1);
    
    for (int i=1; i<=n; i++) {
        printf("%d",CBT[i]);
        if (i<n) {
            printf(" ");
        }else{
            printf("\n");
        }
    }
}