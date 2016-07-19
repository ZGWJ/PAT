#include <cstdio>

int main(){
    int k;
    int num,temp=0;
    int time=0;
    scanf("%d",&k);
    
    for (int i=0; i<k; i++) {
        scanf("%d",&num);
        time+=5;
        if (num>temp) {
            time+=(num-temp)*6;
        }else{
            time+=(temp-num)*4;
        }
        temp=num;
    }
    printf("%d",time);
}