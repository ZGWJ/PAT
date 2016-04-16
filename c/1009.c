#include <stdio.h>

int main(){
    char string[81]={};
    char string2[81]={};
    int pos1=-1,pos2=-1;
    scanf("%[^\n]",string);
    
    for (int i=0; i<=80; i++) {
        if (string[i]==' ') {
            pos1=pos2;
            pos2=i;
            string2[79-pos2]=' ';
            if (pos2-pos1>1) {
                for (int j=79-pos2+1,index=1; j<79-pos1; j++,index++) {
                    string2[j]=string[pos1+index];
                }
            }
        }
        if (string[i]=='\0') {
            for (int j=79-i+1,index=1; j<79-pos2; j++,index++) {
                string2[j]=string[pos2+index];
            }
            break;
        }
    }
    
    for (int i=0; i<81; i++) {
        if (string2[i]!='\0') {
            printf("%c",string2[i]);
        }
    }
}