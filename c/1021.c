#include <stdio.h>
#include <stdlib.h>

typedef struct number{
    int id;
    int count;
}number;

int main(){
    char N[1001]={};
    scanf("%s",N);
    number* nb=malloc(10*sizeof(*nb));
    
    for (int i=0; i<10; i++) {
        nb[i].count=0;
        nb[i].id=i;
    }
    for (int i=0; i<1000; i++) {
        switch (N[i]) {
            case '0':
                nb[0].count++;
                break;
            case '1':
                nb[1].count++;
                break;
            case '2':
                nb[2].count++;
                break;
            case '3':
                nb[3].count++;
                break;
            case '4':
                nb[4].count++;
                break;
            case '5':
                nb[5].count++;
                break;
            case '6':
                nb[6].count++;
                break;
            case '7':
                nb[7].count++;
                break;
            case '8':
                nb[8].count++;
                break;
            case '9':
                nb[9].count++;
                break;
            default:
                break;
        }
    }
    for (int i=0; i<10; i++) {
        if (nb[i].count!=0) {
            printf("%d:%d\n",nb[i].id,nb[i].count);
        }
    }
}