#include <stdio.h>

int main(){
    int hour,min,C1,C2;
    float C3,sec;
    scanf("%d %d",&C1,&C2);
    C3=(C2-C1)/100.0;
    hour=C3/3600;
    min=(int)C3%3600/60;
    sec=C3-3600*hour-60*min;
    if (sec-(int)sec>=0.5){
        sec++;
    }
    if ((int)sec==60) {
        sec=0;
        min++;
        if (min==60) {
            min=0;
            hour++;
        }
    }
    printf("%02d:%02d:%02d\n",hour,min,(int)sec);
}