#include <stdio.h>

int main(){
    int A,count=0,B=6,i;
    char a;
    scanf("%d %c",&A,&a);
    
    while ((A-1)/B!=0) {
        A-=B;
        B+=4;
        count++;
    }
    A--;
    B-=4;
    for (i=0; i<count; i++) {
        for (int j=0; j<i; j++) {
            printf(" ");
        }
        for (int j=0; j<B/2; j++) {
            printf("%c",a);
        }
        B-=4;
        printf("\n");
    }
    for (int j=0; j<count; j++) {
        printf(" ");
    }
    printf("%c\n",a);
    B+=4;
    for (i=count-1; i>=0; i--) {
        for (int j=0; j<i; j++) {
            printf(" ");
        }
        for (int j=0; j<B/2; j++) {
            printf("%c",a);
        }
        B+=4;
        printf("\n");
    }
    printf("%d",A);
}