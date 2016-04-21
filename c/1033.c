#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    char ch;
    char* broken=malloc(70*sizeof(char*));
    int brokenkeys[127];
    
    memset(brokenkeys, 0, sizeof(brokenkeys));
    memset(broken, 0, 70*sizeof(char*));

    gets(broken);
    
    for (int i=0; broken[i]; i++) {
        brokenkeys[broken[i]]=1;
        if (isupper(broken[i])) {
            brokenkeys[broken[i]-('A'-'a')]=1;
        }
        if (broken[i]=='+') {
            for (int j='A'; j<='Z'; j++) {
                brokenkeys[j]=1;
            }
        }
    }
    
    while((scanf("%c",&ch))!=EOF){
        if (brokenkeys[ch]==0) {
            printf("%c",ch);
        }
    }
}