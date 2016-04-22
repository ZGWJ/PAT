#include <stdio.h>

int main(){
    int a1,a2,a3,b1,b2,b3,d1,d2,d3,flag=0;
    long long c1,c2,c3;
    scanf("%d.%d.%d %d.%d.%d",&a1,&a2,&a3,&b1,&b2,&b3);
    
    c1=17*29*a1+29*a2+a3;
    c2=17*29*b1+29*b2+b3;
    c3=c2-c1;
    if (c3<0) {
        flag=1;
        c3=-c3;
    }
    d1=c3/(17*29);
    d2=c3%(17*29)/29;
    d3=c3%29;
    if (flag==0) {
        printf("%d.%d.%d",d1,d2,d3);
    }else{
        printf("-%d.%d.%d",d1,d2,d3);
    }
}