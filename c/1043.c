#include <stdio.h>
#include <string.h>

int main(){
    char a;
    int P=0,A=0,T=0,e=0,s=0,t=0;
    while (scanf("%c",&a)!=EOF) {
        if (a=='P') {
            P++;
        }else if (a=='A'){
            A++;
        }else if (a=='T'){
            T++;
        }else if (a=='e'){
            e++;
        }else if (a=='s'){
            s++;
        }else if (a=='t'){
            t++;
        }else{
            continue;
        }
    }
    
    while (P!=0||A!=0||T!=0||e!=0||s!=0||t!=0) {
        if (P!=0) {
            printf("P");
            P--;
        }
        if (A!=0) {
            printf("A");
            A--;
        }
        if (T!=0) {
            printf("T");
            T--;
        }
        if (e!=0) {
            printf("e");
            e--;
        }
        if (s!=0) {
            printf("s");
            s--;
        }
        if (t!=0) {
            printf("t");
            t--;
        }
    }
}