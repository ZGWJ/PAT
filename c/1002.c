#include <stdio.h>
#include <string.h>

int main(){
    int sum=0;
    char sum_str[4]={0};
    char num[101]={0};
    scanf("%s",num);
    char *temp=num;
    char *temp1=sum_str;
    while (*temp!='\0') {
        sum+=*temp-'0';
        temp++;
    }
    sprintf(sum_str,"%d",sum);
    
    while (*temp1!='\0') {
        switch (*temp1) {
            case '0':
                printf("ling");
                break;
            case '1':
                printf("yi");
                break;
            case '2':
                printf("er");
                break;
            case '3':
                printf("san");
                break;
            case '4':
                printf("si");
                break;
            case '5':
                printf("wu");
                break;
            case '6':
                printf("liu");
                break;
            case '7':
                printf("qi");
                break;
            case '8':
                printf("ba");
                break;
            case '9':
                printf("jiu");
                break;
            default:
                break;
        }
        temp1++;
        if (*temp1!='\0') {
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}