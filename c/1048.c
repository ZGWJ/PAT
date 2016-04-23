#include <stdio.h>
#include <string.h>

int main(){
    char A[101]={},B[101]={},C[101]={};
    int len1=0,len2=0,c,num;
    
    scanf("%s %s",A,B);
    len1=(int)strlen(A);
    len2=(int)strlen(B);
    if (len1>len2) {
        num=len1-len2;
        for (int i=0; i<num; i++) {
            C[i]='0';
        }
        for (int i=0; i<len2; i++) {
            C[i+num]=B[i];
        }
    }
    if (len2>=len1) {
        for (int i=len2-len1; i<len2; i++) {
            if ((len2-i)%2==0) {
                if (B[i]>=A[i+len1-len2]) {
                    B[i]=B[i]-A[i+len1-len2]+'0';
                }else{
                    B[i]=B[i]-A[i+len1-len2]+'0'+10;
                }
            }else{
                c=(A[i+len1-len2]+B[i]-'0'-'0')%13;
                if (c<10) {
                    B[i]=c+'0';
                }else if (c==10){
                    B[i]='J';
                }else if (c==11){
                    B[i]='Q';
                }else if (c==12){
                    B[i]='K';
                }
            }
        }
    }else{
        for (int i=0; i<len1; i++) {
            if ((len1-i)%2==0) {
                if (C[i]>=A[i]) {
                    C[i]=C[i]-A[i]+'0';
                }else{
                    C[i]=C[i]-A[i]+'0'+10;
                }
            }else{
                c=(A[i]+C[i]-'0'-'0')%13;
                if (c<10) {
                    C[i]=c+'0';
                }else if (c==10){
                    C[i]='J';
                }else if (c==11){
                    C[i]='Q';
                }else if (c==12){
                    C[i]='K';
                }
            }
        }
    }
    if (len1>len2) {
        for (int i=0; i<len1; i++) {
            printf("%c",C[i]);
        }
        printf("\n");
    }else{
        for (int i=0; i<len2; i++) {
            printf("%c",B[i]);
        }
        printf("\n");
    }
}