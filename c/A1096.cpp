#include <cstdio>
#include <cmath>

int a;

int main(){
    scanf("%d",&a);
    
    int len=-1,last=-1;
    
    for (int i=2; i<=(long long)sqrt(1.0*a)+1; i++) {
        long long temp=1;
        int j=i;
        while (1) {
            temp*=j;
            if (a%temp!=0) {
                break;
            }
            if (j-i+1>len) {
                len=j-i+1;
                last=j;
            }
            j++;
        }
    }
    
    if (len==-1) {
        printf("1\n");
        printf("%d\n",a);
    }else{
        printf("%d\n",len);
        
        for (int i=last-len+1; i<=last; i++) {
            if (i!=last) {
                printf("%d*",i);
            }else{
                printf("%d\n",i);
            }
        }
    }
}