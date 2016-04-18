#include <stdio.h>
#include <math.h>

int main(){
    int A1=0,A2=0,A3=0,A5=0,n=0,num=0,index=0,count=0;
    float A4=0.0f;
    
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&num);
        if (num%5==0&&num%2==0) {
            A1+=num;
        }
        if (num%5==1) {
            A2+=pow(-1, index)*num;
            index++;
        }
        if (num%5==2) {
            A3++;
        }
        if (num%5==3) {
            A4+=num;
            count++;
        }
        if (num%5==4) {
            if (num>A5) {
                A5=num;
            }
        }
    }
    if (count!=0) {
        A4=A4/count;
    }
    
    for (int i=1; i<=5; i++) {
        switch (i) {
            case 1:
                if (A1) {
                    printf("%d ",A1);
                }
                else{
                    printf("N ");
                }
                break;
            case 2:
                if (index!=0) {
                    printf("%d ",A2);
                }
                else{
                    printf("N ");
                }
                break;
            case 3:
                if (A3) {
                    printf("%d ",A3);
                }
                else{
                    printf("N ");
                }
                break;
            case 4:
                if (A4) {
                    printf("%.1f ",A4);
                }
                else{
                    printf("N ");
                }
                break;
            case 5:
                if (A5) {
                    printf("%d",A5);
                }
                else{
                    printf("N");
                }
                break;
            default:
                break;
        }
    }
}