#include <stdio.h>
#include <stdlib.h>

int main(){
    char num[10000]={},E[5]={};
    int E1;
    scanf("%s",num);
    for (int i=0; i<10000; i++) {
        if (num[i]=='E') {
            i++;
            for (int j=0; num[i]!='\0'; i++,j++) {
                E[j]=num[i];
            }
            break;
        }
    }
    
    E1=atoi(E);
    if (E1>=0) {
        if (num[0]=='-') {
            printf("-");
        }
        for (int i=1; num[i]!='E'; i++) {
            if (num[i]!='.') {
                printf("%c",num[i]);
            }
            if (i==E1+2) {
                if (num[i+1]!='E') {
                    printf(".");
                }
            }
            if(num[i+1]=='E'&&i<E1+2){
                for (int j=0; j<E1-1; j++) {
                    printf("0");
                }
            }
        }
    }else{
        if (num[0]=='-') {
            printf("-");
        }
        printf("0.");
        while ((E1+1)!=0) {
            printf("0");
            E1++;
        }
        for (int i=1; num[i]!='E'; i++) {
            if (num[i]!='.') {
                printf("%c",num[i]);
            }
        }
    }
}