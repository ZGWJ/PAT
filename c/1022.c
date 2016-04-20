#include <stdio.h>

int main(){
    char A[31]={};
    int a,b,c,d,N,i=30;
    scanf("%d %d %d",&a,&b,&N);
    c=a+b;
    while (c>=N) {
        d=c%N;
        c=c/N;
        A[i]=d+'0';
        i--;
    }
    A[i]=c+'0';
    for (int j=0; j<31; j++) {
        if (A[j]!=0) {
            printf("%c",A[j]);
        }
    }
}