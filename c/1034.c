#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long gcd(long long a,long long b){
    if (!b) {
        return a;
    }else{
        return gcd(b, a%b);
    }
}

void AB123(long long* a,long long* b,long long* c,long long* d){
    *c=(*a)/(*b);
    if (*c!=0) {
        *d=llabs(*a%*b);
    }else{
        *d=*a%*b;
    }
}

void gongyueshu(long long* a,long long* b){
    long long n=llabs(gcd(*a, *b));
        *a=*a/n;
        *b=*b/n;
}

void print1(long long A2,long long A3,long long A4){
    if (A3!=0) {
        if (A4!=0) {
            if (A3>0) {
                printf("%lld %lld/%lld",A3,A4,A2);
            }else{
                printf("(%lld %lld/%lld)",A3,A4,A2);
            }
        }else{
            if (A3>0) {
                printf("%lld",A3);
            }else{
                printf("(%lld)",A3);
            }
        }
    }else{
        if (A4!=0){
            if (A4<0) {
                printf("(%lld/%lld)",A4,A2);
            }else{
                printf("%lld/%lld",A4,A2);
            }
        }else{
            printf("0");
        }
    }
}

void jia(long long A1,long long A2,long long A3,long long A4,long long B1,long long B2,long long B3,long long B4,long long* C1,long long* C2,long long* C3,long long* C4){
    
    *C1=A1*B2+B1*A2;
    *C2=A2*B2;
    
    if (*C1!=0) {
        gongyueshu(C1, C2);
    }
    AB123(C1, C2, C3, C4);
    
    print1(A2, A3, A4);
    printf(" + ");
    print1(B2, B3, B4);
    printf(" = ");
    print1(*C2, *C3, *C4);
    printf("\n");
    
}

void jian(long long A1,long long A2,long long A3,long long A4,long long B1,long long B2,long long B3,long long B4,long long* C1,long long* C2,long long* C3,long long* C4){
    
    *C1=A1*B2-B1*A2;
    *C2=A2*B2;
    
    if (*C1!=0) {
        gongyueshu(C1, C2);
    }
    AB123(C1, C2, C3, C4);
    
    print1(A2, A3, A4);
    printf(" - ");
    print1(B2, B3, B4);
    printf(" = ");
    print1(*C2, *C3, *C4);
    printf("\n");
    
}

void chen(long long A1,long long A2,long long A3,long long A4,long long B1,long long B2,long long B3,long long B4,long long* C1,long long* C2,long long* C3,long long* C4){
    
    *C1=A1*B1;
    *C2=A2*B2;
    
    if (*C1!=0) {
        gongyueshu(C1, C2);
    }
    AB123(C1, C2, C3, C4);
    
    print1(A2, A3, A4);
    printf(" * ");
    print1(B2, B3, B4);
    printf(" = ");
    print1(*C2, *C3, *C4);
    printf("\n");
    
}

void chu(long long A1,long long A2,long long A3,long long A4,long long B1,long long B2,long long B3,long long B4,long long* C1,long long* C2,long long* C3,long long* C4){
    if (B1!=0) {
        *C1=A1*B2;
        *C2=A2*B1;
        
        if (*C2<0) {
            *C2=llabs(*C2);
            *C1=-*C1;
        }
        
        if (*C1!=0) {
            gongyueshu(C1, C2);
        }
        AB123(C1, C2, C3, C4);
    }
    print1(A2, A3, A4);
    printf(" / ");
    print1(B2, B3, B4);
    printf(" = ");
    if (B4!=0||B3!=0) {
        print1(*C2, *C3, *C4);
    }else{
        printf("Inf");
    }
    printf("\n");
    
}



int main(){
    long long A1,A2,A3,A4,B1,B2,B3,B4,C1,C2,C3,C4;
    scanf("%lld/%lld %lld/%lld",&A1,&A2,&B1,&B2);
    
    if (A1!=0) {
        gongyueshu(&A1, &A2);
    }
    if (B1!=0) {
        gongyueshu(&B1, &B2);
    }
    AB123(&A1, &A2, &A3, &A4);
    AB123(&B1, &B2, &B3, &B4);
    
    jia(A1, A2, A3, A4, B1, B2, B3, B4, &C1, &C2, &C3, &C4);
    jian(A1, A2, A3, A4, B1, B2, B3, B4, &C1, &C2, &C3, &C4);
    chen(A1, A2, A3, A4, B1, B2, B3, B4, &C1, &C2, &C3, &C4);
    chu(A1, A2, A3, A4, B1, B2, B3, B4, &C1, &C2, &C3, &C4);
}
