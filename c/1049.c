#include <stdio.h>

int main(){
    double N;
    scanf("%lf",&N);
    double a=0,sum=0;
    
    for (int i=0; i<N; i++) {
        scanf("%lf",&a);
        sum+=a*(double)(N-i)*(double)(i+1);
    }
    
    printf("%.2lf",sum);
}