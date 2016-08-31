#include <cstdio>
#include <string.h>

char num[30]={0};

char num1[30]={0};

int count[13]={0};

int count1[13]={0};

int atoi(char n){
    return n-'0';
}

void fuck(){
    int length=(int)strlen(num);
    int flag=0;
    
    for (int i=length-1; i>=0; i--) {
        int temp=atoi(num[i]);
        
        num1[i+1]=(temp*2)%10+'0';
        
        if (flag==1) {
            num1[i+1]++;
        }
        
        if (temp*2>=10) {
            flag=1;
        }else{
            flag=0;
        }
    }
    
    if (flag==1) {
        num1[0]='1';
    }
}

int main(){
    scanf("%s",num);
    
    for (int i=0; i<strlen(num); i++) {
        count[atoi(num[i])]++;
    }
    
    fuck();
    
    if (num1[0]=='1') {
        printf("No\n");
        for (int i=0; i<=strlen(num1); i++) {
            printf("%c",num1[i]);
        }
        printf("\n");
        return 0;
    }
    
    for (int i=1; i<=strlen(num); i++) {
        count1[atoi(num1[i])]++;
    }
    
    
    int flag1=0;
    
    for (int i=0; i<11; i++) {
        if (count[i]!=count1[i]) {
            flag1=1;
        }
    }
    
    if (flag1==0) {
        printf("Yes\n");
        for (int i=1; i<=strlen(num); i++) {
            printf("%c",num1[i]);
        }
        printf("\n");
    }else{
        printf("No\n");
        for (int i=1; i<=strlen(num); i++) {
            printf("%c",num1[i]);
        }
        printf("\n");
    }
    
    return 0;
}