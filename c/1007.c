#include <stdio.h>

int main(){
    int num[100000];
    int prime[10000]={};
    int n=0;
    int index=0;
    
    int m;
    scanf("%d",&m);
    for (int i=0; i<100000; i++) {
        num[i]=1;
    }
    for (int i=2; i*i<=m; i++) {
        if (num[i]==0) {
            continue;
        }
        for (int j=i*i; j<=m; j=j+i) {
            num[j]=0;
        }
    }
    
    for (int i=2; i<=m; i++) {
        if (num[i]==1) {
            prime[index++]=i;
        }
    }
    
    for (int i=0; i<m; i++) {
        if (prime[i+1]=='\0') {
            break;
        }
        if (prime[i+1]-prime[i]==2) {
            n++;
        }
    }
    printf("%d",n);
}