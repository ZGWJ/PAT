#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int N,count=0,count_point=0,count_fu=0,flag=0,k=0,count_shit=0;
    double sum=0,f=0;
    scanf("%d",&N);
    char fuck[101]={};
    
    for (int i=0; i<N; i++) {
        scanf("%s",fuck);
        for (int j=0; fuck[j]; j++) {
            if (!(fuck[j]>='0'&&fuck[j]<='9')) {
                if (fuck[j]=='-'||fuck[j]=='+') {
                    count_fu++;
                    if (count_fu>1) {
                        printf("ERROR: %s is not a legal number\n",fuck);
                        flag=1;
                        break;
                    }
                }else if (fuck[j]=='.') {
                    count_point++;
                    if (count_point>1) {
                        printf("ERROR: %s is not a legal number\n",fuck);
                        flag=1;
                        break;
                    }
                }else{
                    printf("ERROR: %s is not a legal number\n",fuck);
                    flag=1;
                    break;
                }
            }
        }
        for(k=0;fuck[k]!='.'&&fuck[k]!=0;k++){
            ;
        }
        count_shit=0;
        for(k;fuck[k];k++)
        {
            count_shit++;
        }
        if(count_shit>3)
        {
            if (flag==0) {
                printf("ERROR: %s is not a legal number\n",fuck);
            }
            flag=1;
        }
        if (flag==0) {
            sscanf(fuck,"%lf",&f);
            if (f>1000.00||f<-1000.00) {
                printf("ERROR: %s is not a legal number\n",fuck);
            }else{
                count++;
                sum+=f;
            }
        }
        flag=0;
        count_point=0;
        count_fu=0;
    }
    if (count==0) {
        printf("The average of 0 numbers is Undefined\n");
    }else if(count==1){
        printf("The average of %d numbers is %.2lf\n",count,sum);
    }else{
        printf("The average of %d numbers is %.2lf\n",count,sum/count);
    }
}