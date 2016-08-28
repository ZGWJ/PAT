#include <cstdio>
#include <cmath>

const int N=11111;

bool hashTable[N]={0};

int Msize,n;

bool isprime(int n){
    if (n<=1) {
        return false;
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
    int a;
    
    scanf("%d %d",&Msize,&n);
    
    while (isprime(Msize)==false) {
        Msize++;
    }
    
    for (int i=0; i<n; i++) {
        scanf("%d",&a);
        
        int M=a%Msize;
        
        if (hashTable[M]==false) {
            hashTable[M]=true;
            if (i==0) {
                printf("%d",M);
            }else{
                printf(" %d",M);
            }
        }else{
            int step;
            for (step=1; step<Msize; step++) {
                M=(a+step*step)%Msize;
                if (hashTable[M]==false) {
                    hashTable[M]=true;
                    if (i==0) {
                        printf("%d",M);
                    }else{
                        printf(" %d",M);
                    }
                    break;
                }
            }
            
            if (step>=Msize) {
                if (i>0) {
                    printf(" ");
                }
                printf("-");
            }
        }
    }
    return 0;
}