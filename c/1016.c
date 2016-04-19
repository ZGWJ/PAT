#include <stdio.h>
#include <math.h>

int main(){
    char A[10]={},B[10]={};
    int DA,DB,flag1=0,flag2=0,res1=0,res2=0,res=0;
    
    scanf("%s%d%s%d",A,&DA,B,&DB);
    
    for (int i=0; i<10; i++) {
        if (A[i]==DA+'0') {
            flag1++;
        }
        if (B[i]==DB+'0') {
            flag2++;
        }
    }
    for (int i=flag1; i>0; i--) {
        res1+=DA*pow(10,i-1);
    }
    for (int i=flag2; i>0; i--) {
        res2+=DB*pow(10, i-1);
    }
    res=res1+res2;
    printf("%d",res);
}