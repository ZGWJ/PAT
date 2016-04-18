#include <stdio.h>

int main(){
    int day=0,clock=-1,min=-1,count=1,count1=1;
    char str1[61]={},str2[61]={},str3[61]={},str4[61]={};
    scanf("%s%s%s%s",str1,str2,str3,str4);
    
    for (int i=0; i<60; i++) {
        if ((str2[i]==str1[i])&&((str1[i]>='A'&&str1[i]<='Z')||(str1[i]>='0'&&str1[i]<='9'))) {
            if(count<=2){
                if (str1[i]>='A'&&str1[i]<='Z') {
                    if (count==1) {
                        if(str1[i]>='A'&&str1[i]<='G'){
                            day=str1[i]-'A'+1;
                            count++;
                        }
                    }
                    else{
                        if(count==2){
                            if(str1[i]>='A'&&str1[i]<='N'){
                            clock=str1[i]-'A'+10;
                            count++;
                            }
                        }
                    }
                }
                else{
                    if(count==2){
                        clock=str1[i]-'0';
                        count++;
                    }
                }
            }
        }
        
        if (count1==1&&(str3[i]==str4[i])&&((str3[i]>='A'&&str3[i]<='Z')||(str3[i]>='a'&&str3[i]<='z'))) {
            min=i;
            count1++;
        }
    }
    
    switch (day) {
        case 1:
            printf("MON ");
            break;
        case 2:
            printf("TUE ");
            break;
        case 3:
            printf("WED ");
            break;
        case 4:
            printf("THU ");
            break;
        case 5:
            printf("FRI ");
            break;
        case 6:
            printf("SAT ");
            break;
        case 7:
            printf("SUN ");
            break;
        default:
            break;
    }
    printf("%02d:%02d",clock,min);

}