#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar2(const void*pa,const void*pb){
    return strcmp((char*)pb, (char*)pa);
}
int compar1(const void*pa,const void*pb){
    return strcmp((char*)pa, (char*)pb);
}

void itoa(char num[],int num1){
    int a,b,c;
    a=num1/1000;
    b=(num1-a*1000)/100;
    c=(num1-a*1000-b*100)/10;
    num[0]=a+'0';
    num[1]=b+'0';
    num[2]=c+'0';
    num[3]=num1%10+'0';
}

int main(){
    char num[5]={'0','0','0','0','\0'},num1[5]={'0','0','0','0','\0'},num2[5]={'0','0','0','0','\0'};
    int a,b,c,number;
    scanf("%d",&number);
    itoa(num, number);
    if ((num[0]==num[1])&&(num[0]==num[2])&&(num[0]==num[3])) {
        int d=atoi(num);
        printf("%04d - %04d = 0000",d,d);
        return 0;
    }
    while (c!=6174) {
        qsort(num, 4, sizeof(char), compar2);
        for (int i=0; i<4; i++) {
            num1[i]=num[i];
        }
        qsort(num, 4, sizeof(char), compar1);
        for (int i=0; i<4; i++) {
            num2[i]=num[i];
        }
        a=atoi(num1);
        b=atoi(num2);
        c=a-b;
        printf("%04d - %04d = %04d\n",a,b,c);
        itoa(num,c);
    }
    return 0;
}