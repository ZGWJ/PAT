#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int num=127,max=0;
    int asc[130]={};
    char all[1001]={};
    scanf("%[^\n]",all);
    for (int i=0; i<strlen(all); i++) {
        if(all[i]==' '){
            continue;
        }
        if (isupper(all[i])) {
            asc[all[i]+('a'-'A')]++;
        }else{
            asc[all[i]]++;
        }
    }

    for (int i='a'; i<='z'; i++) {
        if (asc[i]>max) {
            num=i;
            max=asc[i];
        }
    }
    printf("%c %d",num,asc[num]);
}