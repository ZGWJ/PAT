#include <stdio.h>

int main(){
    int hour,min,sec,C1,C2,C3;
    scanf("%d %d",&C1,&C2);
    C3=C2-C1;
    if (C3%100>=50) {
        C3+=50;
    }
    C3=C3/100;
    hour=C3/3600;
    min=C3%3600/60;
    sec=C3%60;
    printf("%02d:%02d:%02d\n",hour,min,sec);
}