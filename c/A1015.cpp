#include <cstdio>
#include <cmath>

int d[111];

bool isprime(int n){
    if (n<=1) {
        return  false;
    }
    int sqr=(int)sqrt(1.0*n);
    
    for (int i=2; i<=sqr; i++) {
        if (n%i==0) {
            return false;
        }
    }
    
    return true;
}

int main(){
    int a,b;
    for (; ; ) {
        scanf("%d",&a);
        if (a<0) {
            break;
        }
        scanf("%d",&b);
        
        if (isprime(a)==false) {
            printf("No\n");
        }else{
            int len=0;
            
            do {
                d[len++]=a%b;
                a/=b;
            } while (a!=0);
            
            for (int i=0; i<len; i++) {
                a=a*b+d[i];
            }
            
            if (isprime(a)==true) {
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    
    return 0;
}