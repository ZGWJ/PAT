#include <stdio.h>

int main(){
    int N,flag=0;
    char num[20]={};
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    
    scanf("%d",&N);
    for (int i=0,sum=0,flag2=0; i<N; i++) {
        scanf("%s",num);
        for (int j=0; j<17; j++) {
            if (num[j]>='0'&&num[j]<='9') {
                sum+=(num[j]-'0')*weight[j];
            }else{
                for (int l=0; l<18; l++) {
                    printf("%c",num[l]);
                }
                printf("\n");
                flag=1;
                flag2=1;
                break;
            }
        }
        if (flag2==0) {
            sum=sum%11;
            if (num[17]!=M[sum]) {
                for (int l=0; l<18; l++) {
                    printf("%c",num[l]);
                }
                printf("\n");
                flag=1;
            }
        }
        flag2=0;
        sum=0;
    }
    if (flag==0) {
        printf("All passed");
    }
}