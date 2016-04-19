#include <stdio.h>

int max(int a,int b,int c){
    if ((a>=b&&b>=c)||(a>=c&&c>=b)) {
        return a;
    }else if((b>=a&&a>=c)||(b>=c&&c>=a)){
        if (b==a) {
            return a;
        }else{
            return b;
        }
    }else{
        if (c==a) {
            return a;
        }else if (c==b){
            return b;
        }else{
            return c;
        }
    }
}

int main(){
    int N,A1=0,A2=0,A3=0,B1=0,B2=0,B3=0,C1=0,C2=0,C3=0,D1=0,D2=0,D3=0;
    char A,B;
    scanf("%d",&N);
    getchar();
    for (int i=0; i<N; i++) {
        scanf("%c %c",&A,&B);
        getchar();
        if (A=='C') {
            if (B=='C') {
                A2++;B2++;
            }else if(B=='J'){
                A1++;B3++;C2++;
            }else{
                A3++;B1++;D1++;
            }
        }else if (A=='J'){
            if (B=='C') {
                A3++;B1++;D2++;
            }else if(B=='J'){
                A2++;B2++;
            }else{
                A1++;B3++;C3++;
            }
        }else{
            if (B=='C') {
                A1++;B3++;C1++;
            }else if(B=='J'){
                A3++;B1++;D3++;
            }else{
                A2++;B2++;
            }
        }
    }
    printf("%d %d %d\n",A1,A2,A3);
    printf("%d %d %d\n",B1,B2,B3);
    if (max(C1, C2, C3)==C1) {
        printf("B ");
    }else if (max(C1, C2, C3)==C2){
        printf("C ");
    }else{
        printf("J ");
    }
    if (max(D1, D2, D3)==D1) {
        printf("B");
    }else if (max(D1, D2, D3)==D2){
        printf("C");
    }else{
        printf("J");
    }
}