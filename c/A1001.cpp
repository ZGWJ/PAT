#include <stdio.h>
#include <string.h>

int main(){
    int a,b,c;
    int flag=0;
    long num,num2;
    
    char d[9];
    
    for (int i=0; i<=8; i++) {
        d[i]='\0';
    }
    
    scanf("%d %d",&a,&b);
    
    c=a+b;
    
    if (c>=0) {
        sprintf(d,"%d",c);
    }else{
        flag=1;
        c=-c;
        sprintf(d,"%d",c);
    }
    
    num=strlen(d);
    
    num2=num%3;
    
    if (num2==0) {
        num2=3;
    }
    
    if (flag==1) {
        printf("-");
    }
    
    if (num>3) {
        for (int i=0; i<=num2-1; i++) {
            printf("%c",d[i]);
        }
        printf(",");
        
        int count=0;
        for (int i=(int)num2; i<=num-1; i++) {
            printf("%c",d[i]);
            count++;
            if (count==3&&d[i+1]!='\0') {
                printf(",");
                count=0;
            }
        }
    }else{
        for (int i=0; i<=num-1; i++) {
            printf("%c",d[i]);
        }
    }
}