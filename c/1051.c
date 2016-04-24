#include <stdio.h>
#include <math.h>

int main(){
    double R1,R2,P1,P2,A1,A2,B1,B2,C1,C2;
    scanf("%lf %lf %lf %lf",&R1,&P1,&R2,&P2);
    
    A1=R1*cos(P1);
    A2=R1*sin(P1);
    
    B1=R2*cos(P2);
    B2=R2*sin(P2);
    
    C1=(A1*B1-A2*B2);
    C2=(A1*B2+A2*B1);
    

    if (fabs(C1) < 0.001) {
        if (fabs(C2) < 0.001) {
            printf("0\n");
        } else if(C2 > 0){
            printf("0.00+%.2lfi\n", C2);
        } else {
            printf("0.00%.2lfi\n", C2);
        }
    } else {
        if (fabs(C2) < 0.001) {
            printf("%.2lf+0.00i\n", C1);
        } else if (C2 > 0) {
            printf("%.2lf+%.2lfi\n", C1, C2);
        } else {
            printf("%.2lf%.2lfi\n", C1, C2);
        }
    }
}