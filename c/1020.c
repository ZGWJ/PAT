#include <stdio.h>
#include <stdlib.h>

typedef struct yuebing{
    float store,price;
}yuebing;

int compar(const void* pa,const void* pb){
    yuebing a=*(yuebing*)pa;
    yuebing b=*(yuebing*)pb;
    float ret;
    ret=b.price-a.price;
    if (ret>0) {
        ret=1.0;
    }else if (ret<0){
        ret=-1.0;
    }
    
    return ret;
}

int main(){
    int n;
    float require;
    float profit=0.0;
    scanf("%d %f",&n,&require);
    yuebing *yb=malloc(n*sizeof(*yb));
    
    for (int i=0; i<n; i++) {
        scanf("%f",&yb[i].store);
    }
    for (int i=0; i<n; i++) {
        scanf("%f",&yb[i].price);
        yb[i].price=yb[i].price/yb[i].store;
    }
    qsort(yb, n, sizeof(*yb), compar);
    
    for (int i=0; i<n; i++) {
        if (require>yb[i].store) {
            require-=yb[i].store;
            profit+=yb[i].price*yb[i].store;
        }else{
            profit+=require*yb[i].price;
            break;
        }
    }
    printf("%.2f",profit);
}