#include <stdio.h>
#include <stdlib.h>

int compar(const void* pa,const void*pb){
    int a=*(int*)pa;
    int b=*(int*)pb;
    int ret;
    ret=a-b;
    return ret;
}

int main(){
    int N,maxcount=1,count=0;
    float p;
    scanf("%d %f",&N,&p);
    int* num=malloc(N*sizeof(int*));
    for (int i=0; i<N; i++) {
        scanf("%d",&num[i]);
    }
    
    qsort(num, N, sizeof(int), compar);
    
    for (int i=0; i<N; i++) {
        for (int j=i+maxcount-1; j<N; j++) {
            if (num[i]*p>=num[j]) {
                maxcount+=count;
                count=1;
            }else{
                break;
            }
        }
        count=0;
        if (N-i<=maxcount) {
            break;
        }
    }
    printf("%d",maxcount);
}