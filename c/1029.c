#include <stdio.h>

int main(){
    char A[81]={},B[81]={},C[64]={},D[64]={};
    scanf("%s",A);
    scanf("%s",B);
    
    for (int i=0,j=0,l=0,flag1=0,flag2=0; i<81; i++) {
        flag1=flag2=0;
        if (A[i]!=0) {
            for (int k=0; C[k]!='\0'; k++) {
                if (C[k]>='A'&&C[k]<='Z') {
                    if (C[k]==A[i]+('A'-'a')) {
                        flag1=1;
                        break;
                    }
                    
                }
                if (C[k]>='a'&&C[k]<='z') {
                    if (C[k]==A[i]-('A'-'a')) {
                        flag1=1;
                        break;
                    }
                    
                }
                if (C[k]==A[i]) {
                    flag1=1;
                    break;
                }
            }
            if (flag1==0) {
                C[j]=A[i];
                j++;
                flag1=0;
            }
        }
        if (B[i]!=0) {
            for (int k=0; D[k]!='\0'; k++) {
                if (D[k]==B[i]) {
                    flag2=1;
                    break;
                }
            }
            if (flag2==0) {
                D[l]=B[i];
                l++;
                flag2=0;
            }
        }
    }
    
    for (int i=0,flag=0; C[i]!=0; i++) {
        flag=0;
        for (int j=0; D[j]!=0; j++) {
            if (D[j]==C[i]) {
                flag=1;
                break;
            }
            if (D[j]>='a'&&D[j]<='z') {
                if (D[j]==C[i]-('A'-'a')) {
                    flag=1;
                    break;
                }
            }
            if (D[j]>='A'&&D[j]<='Z') {
                if (D[j]==C[i]+('A'-'a')) {
                    flag=1;
                    break;
                }
            }
        }
        if (flag==0) {
            if (C[i]>='a'&&C[i]<='z') {
                printf("%c",C[i]+('A'-'a'));
            }else{
                printf("%c",C[i]);
            }
        }
    }
}