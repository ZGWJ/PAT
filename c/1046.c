#include <stdio.h>

int main(){
    int N,a1,a2,b1,b2,count1=0,count2=0;
    scanf("%d",&N);

    for (int i=0; i<N; i++) {
        scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
        if (a2!=b2) {
            if (a2==a1+b1) {
                count2++;
            }else if(b2==a1+b1){
                count1++;
            }
        }
    }
    printf("%d %d",count1,count2);
}