#include <stdio.h>

int main(){
    double N;
    scanf("%lf",&N);
    double a=0,sum=0;
    
    for (int i=0; i<N; i++) {
        scanf("%lf",&a);
        sum+=a*(double)(N-i)*(double)(i+1);
        //比如，2.6在double下是2.599999999...，若乘int则误差放大导致错误！！故
        //必须乘double!!!!!
    }
    
    printf("%.2lf",sum);
}