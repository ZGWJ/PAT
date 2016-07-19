#include <cstdio>

int main(){
    int k1,k2,total=0;
    double num1[30],num2[30];
    double ans[1000010]={0};
    
    scanf("%d",&k1);
    for (int i=1; i<=2*k1; i++) {
        scanf("%lf",&num1[i]);
    }
    scanf("%d",&k2);
    for (int i=1; i<=2*k2; i++) {
        scanf("%lf",&num2[i]);
    }
    
    for (int i=1; i<=2*k1; i+=2) {
        for (int j=1; j<=2*k2; j+=2) {
            ans[(int)(num1[i]+num2[j])]+=num1[i+1]*num2[j+1];
        }
    }
    
    for (int i=1000009; i>=0; i--) {
        if (ans[i]!=0) {
            total+=1;
        }
    }
    
    printf("%d",total);
    
    for (int i=1000009; i>=0; i--) {
        if (ans[i]!=0) {
            printf(" %d %.1lf",i,ans[i]);
        }
    }
}