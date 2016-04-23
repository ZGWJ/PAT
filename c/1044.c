#include <stdio.h>
#include <stdlib.h>

int main(){
    char mar[2][13][5]={{"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"},{"None","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"}};
    char num[10]={};
    int N,earth,num1=0,num2=0,flag=0,flag1=0,flag2=0,target=0,flag3=0;
    scanf("%d",&N);
    getchar();
    for (int i=0; i<N; i++) {
        scanf("%[^\n]",num);
        if (i<N-1) {
            getchar();
        }
        if (num[0]>='0'&&num[0]<='9') {
            earth=atoi(num);
            num1=earth/13;
            num2=earth%13;
            if (num1!=0) {
                for (int j=0; j<5; j++) {
                    if (mar[1][num1][j]=='\0') {
                        break;
                    }
                    printf("%c",mar[1][num1][j]);
                }
                if (num2!=0) {
                    printf(" ");
                    for (int j=0; j<5; j++) {
                        if (mar[0][num2][j]=='\0') {
                            break;
                        }
                        printf("%c",mar[0][num2][j]);
                    }
                }
                printf("\n");
            }else{
                for (int j=0; j<5; j++) {
                    if (mar[0][num2][j]=='\0') {
                        break;
                    }
                    printf("%c",mar[0][num2][j]);
                }
                printf("\n");
            }
        }else{
            if (num[3]==0) {
                flag3=0;
                flag=0;
                for (int j=0; j<13; j++) {
                    for (int k=0; k<3; k++) {
                        if (num[k]!=mar[0][j][k]) {
                            flag=1;
                            break;
                        }
                    }
                    if (flag==0) {
                        printf("%d\n",j);
                        flag3=1;
                        break;
                    }
                    flag=0;
                }
                if (flag3==0) {
                    flag=0;
                    for (int j=1; j<13; j++) {
                        for (int k=0; k<3; k++) {
                            if (num[k]!=mar[1][j][k]) {
                                flag=1;
                                break;
                            }
                        }
                        if (flag==0) {
                            printf("%d\n",j*13);
                            break;
                        }
                        flag=0;
                    }
                }
            }else if (num[3]==' '){
                flag1=0;
                for (int j=1; j<13; j++) {
                    for (int k=0; k<3; k++) {
                        if (num[k]!=mar[1][j][k]) {
                            flag1=1;
                            break;
                        }
                    }
                    if (flag1==0) {
                        target=j;
                        break;
                    }
                    flag1=0;
                }
                for (int j=1; j<13; j++) {
                    flag2=0;
                    for (int k=0; k<3; k++) {
                        if (num[k+4]!=mar[0][j][k]) {
                            flag2=1;
                            break;
                        }
                    }
                    if (flag2==0) {
                        printf("%d\n",j+target*13);
                        break;
                    }
                    flag2=0;
                }
            }else{
                printf("0\n");
            }
        }
    }
}