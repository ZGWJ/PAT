#include <cstdio>

int findLargestDigit(double num[]){
    double temp=-1;
    int number=-1;;
    for (int i=0; i<3; i++) {
        if (num[i]>temp) {
            temp=num[i];
            number=i+1;
        }
    }
    return number;
}

int main(){
    double a[3],b[3],c[3];
    int win[3];
    double profit;
    
    scanf("%lf %lf %lf",&a[0],&a[1],&a[2]);
    scanf("%lf %lf %lf",&b[0],&b[1],&b[2]);
    scanf("%lf %lf %lf",&c[0],&c[1],&c[2]);
    
    win[0]=findLargestDigit(a);
    win[1]=findLargestDigit(b);
    win[2]=findLargestDigit(c);
    
    for (int i=0; i<3; i++) {
        if (win[i]==1) {
            printf("W ");
        }else if (win[i]==2){
            printf("T ");
        }else{
            printf("L ");
        }
    }
    
    profit=(a[win[0]-1]*b[win[1]-1]*c[win[2]-1]*0.65-1)*2;
    
    printf("%.2lf",(int)((profit*1000)+0.1)/1000.0);
    
    return 0;
}