#include <cstdio>
#include <vector>

using namespace std;

int a,b,c;

void switch1(int n){
    vector<int> ans;
    
    while (n/13!=0) {
        ans.push_back(n%13);
        n=n/13;
    }
    
    ans.push_back(n%13);
    
    if (ans.size()==1) {
        printf("0");
    }
    
    for (int i=(int)ans.size()-1; i>=0; i--) {
        if (ans[i]>=0&&ans[i]<=9) {
            printf("%d",ans[i]);
        }else{
            printf("%c",'A'+ans[i]-10);
        }
    }
    
}

int main(){
    scanf("%d %d %d",&a,&b,&c);
    
    printf("#");
    
    switch1(a);
    switch1(b);
    switch1(c);
    
    printf("\n");
    
    return 0;
}