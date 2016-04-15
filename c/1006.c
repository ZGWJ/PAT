#include <stdio.h>
#include <stdlib.h>

int main(){
    char num[4]={};
    int index=0;
    scanf("%s",num);
    int ge,shi,bai;
    
    for (int i=0;i<4; i++) {
        if (num[i]=='\0') {
            index=i;
            break;
        }
    }
    
    switch (index) {
        case 1:
            ge=num[0]-'0';
            for (int i=1; i<=ge; i++) {
                printf("%d",i);
            }
            break;
            
        case 2:
            shi=num[0]-'0';
            ge=num[1]-'0';
            for (int i=0; i<shi; i++) {
                printf("S");
            }
            for (int j=1; j<=ge; j++) {
                printf("%d",j);
            }
            break;
        
        case 3:
            bai=num[0]-'0';
            shi=num[1]-'0';
            ge=num[2]-'0';
            
            for (int i=0; i<bai; i++) {
                printf("B");
            }
            for (int i=0; i<shi; i++) {
                printf("S");
            }
            for (int j=1; j<=ge; j++) {
                printf("%d",j);
            }
            break;
            
        default:
            break;
    }
}