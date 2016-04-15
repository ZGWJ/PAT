#include <stdio.h>
#include <stdlib.h>

void reverse(int* num,int start,int end){
    int count=(end-start)/2;
    int temp;
    for (int i=0; i<=count; i++) {
        temp=num[start+i];
        num[start+i]=num[end-i];
        num[end-i]=temp;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *num=(int*)malloc(n*sizeof(int));
    
    int m;
    scanf("%d",&m);
    m=m%n;
    
    int p=n-m;
    
    for (int i=0; i<n; i++) {
        int temp;
        scanf("%d",&temp);
        
        num[i]=temp;
    }
    
    if (m>0) {
        reverse(num,0,p-1);
        reverse(num,p,n-1);
        reverse(num,0,n-1);
    }
    
    for (int i=0; i<n; i++) {
        printf("%d",num[i]);
        if (i+1!=n) {
            printf(" ");
        }
    }
}