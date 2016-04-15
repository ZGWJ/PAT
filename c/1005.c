#include <stdio.h>

int main(){
    int n;
    int p=0;
    scanf("%d",&n);
    
    int result[100][100]={};
    int key[100]={};
    
    for (int i=0; i<n; i++) {
        int j=0;
        int num;
        scanf("%d",&num);
        
        result[i][j]=num;
        j++;
        
        while (num!=1) {
            if (num%2==1) {
                num=(3*num+1)/2;
                result[i][j]=num;
                j++;
            }
            else{
                num=num/2;
                result[i][j]=num;
                j++;
            }
        }
    }
    
    for (int k=0; k<100; k++) {
        if (result[k][0]=='\0') {
            break;
        }
        int sign=0;
        for (int l=0; l<100; l++) {
            if (result[l][0]=='\0'||sign==1) {
                break;
            }
            for (int m=1; m<100; m++) {
                if (result[l][m]=='\0') {
                    break;
                }
                if (result[k][0]==result[l][m]) {
                    sign=1;
                    break;
                }
            }
        }
        if (sign==0) {
            key[p]=result[k][0];
            p++;
        }
    }
    int q=99;
    int temp;
    while (q!=0) {
        for (int w=0; w<q; w++) {
            if (key[w+1]=='\0') {
                break;
            }
            if (key[w]<key[w+1]) {
                temp=key[w];
                key[w]=key[w+1];
                key[w+1]=temp;
            }
        }
        q--;
    }
    
    int e=0;
    while (key[e]!='\0') {
        printf("%d",key[e]);
        e++;
        if (key[e]!='\0') {
            printf(" ");
        }
    }
}