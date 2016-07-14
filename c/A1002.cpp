#include <stdio.h>

int main(){
    int num1,num2;
    int count=0;

    double a[30],b[30],c[1001];
    
    for (int i=0; i<30; i++) {
        a[i]=-1;
        b[i]=-1;
    }
    for (int i=0; i<1001; i++) {
        c[i]=-1;
    }
    
    scanf("%d",&num1);
    
    for (int i=1; i<=2*num1; i++) {
        scanf("%lf",&a[i]);
    }
    
    scanf("%d",&num2);
    
    for (int i=1; i<=2*num2; i++) {
        scanf("%lf",&b[i]);
    }
    
    for (int i=1; i<30; i++) {
        if ((i%2)!=0) {
            if (a[i]!=-1) {
                c[(int)a[i]]+=a[i+1];
            }
            if (b[i]!=-1) {
                c[(int)b[i]]+=b[i+1];
            }
        }
    }
    
    for (int i=0; i<1001; i++) {
        if (c[i]!=-1) {
            count++;
        }
    }
    printf("%d",count);
    for (int i=1000; i>=0; i--) {
        if (c[i]!=-1) {
            printf(" %d %.1lf",i,c[i]+1);
        }
    }
}