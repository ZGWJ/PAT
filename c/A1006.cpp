#include <cstdio>
#include <cstring>

struct People{
    char ID[20]={'\0'};
    char sign_in[10]={'\0'};
    char sign_out[10]={'\0'};
}first,last,temp;

int main(){
    int n;
    scanf("%d",&n);
    
    scanf("%s %s %s",temp.ID,temp.sign_in,temp.sign_out);
    strcpy(first.ID, temp.ID);
    strcpy(last.ID, temp.ID);
    strcpy(first.sign_in, temp.sign_in);
    strcpy(last.sign_in, temp.sign_in);
    strcpy(first.sign_out, temp.sign_out);
    strcpy(last.sign_out, temp.sign_out);
    
    for (int i=1; i<n; i++) {
        scanf("%s %s %s",temp.ID,temp.sign_in,temp.sign_out);
        if (strcmp(temp.sign_in, first.sign_in)<0) {
            strcpy(first.ID, temp.ID);
            strcpy(first.sign_in, temp.sign_in);
            strcpy(first.sign_out, temp.sign_out);
        }
        if (strcmp(temp.sign_out, last.sign_out)>0) {
            strcpy(last.ID, temp.ID);
            strcpy(last.sign_in, temp.sign_in);
            strcpy(last.sign_out, temp.sign_out);
        }
    }
    
    printf("%s %s",first.ID,last.ID);
}