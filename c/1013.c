#include <stdio.h>

int main(){
    int M,N;
    scanf("%d%d",&M,&N);
    int num[104730];
    int count=0,count1=1;
    num[0]=num[1]=1;
    
    for (int i=2; i<104730; i++) {
        num[i]=0;
    }
    
    for (int i=2; i*i<104730; i++) {
        if (num[i]==0) {
            for (int j=i*i; j<104730; j=j+i) {
                num[j]=1;
            }
        }
    }
    
    for (int i=0; i<104730; i++) {
        if (num[i]==0) {
            count++;
            if (count>=M&&count<=N) {
                if (count1==1) {
                    printf("%d",i);
                    count1++;
                }
                else if (count1==10){
                    printf(" %d\n",i);
                    count1=1;
                }
                else{
                    printf(" %d",i);
                    count1++;
                }
            }
        }
        if (count>N) {
            break;
        }
    }
}