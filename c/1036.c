#include <stdio.h>

int main(){
    int col,row;
    char c;
    scanf("%d %c",&col,&c);
    
    row=(float)col/2+0.5;
    
    for (int i=0; i<row; i++) {
        if (i==0||i==row-1) {
            for (int j=0; j<col; j++) {
                printf("%c",c);
                if (j==col-1) {
                    printf("\n");
                }
            }
        }else{
            printf("%c",c);
            for (int j=0; j<col-2; j++) {
                printf(" ");
            }
            printf("%c\n",c);
        }
    }
}