#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people{
    char name[10];
    int height;
}people;

int compar(const void*pa,const void*pb){
    people a=*(people*)pa;
    people b=*(people*)pb;
    int ret;
    if (a.height==b.height) {
        ret=(int)strcmp(b.name, a.name);
    }else{
        ret=a.height-b.height;
    }
    
    return ret;
}

void fill1(people a,people* b,int count,int length){
    int n=0,m=1;
    if (count%2==1) {
        while (b[length/2+n].height!=0) {
            n++;
        }
        b[length/2+n].height=a.height;
        for (int i=0; a.name[i]; i++) {
            b[length/2+n].name[i]=a.name[i];
        }
    }else{
        while (b[length/2-m].height!=0) {
            m++;
        }
        b[length/2-m].height=a.height;
        for (int i=0; a.name[i]; i++) {
            b[length/2-m].name[i]=a.name[i];
        }
    }
}

int main(){
    int N,K,rest;
    scanf("%d %d",&N,&K);
    rest=N%K+N/K;
    
    people* ls=malloc(N*sizeof(*ls));
    people* last=malloc(rest*sizeof(*last));
    people* before=malloc(N/K*sizeof(*before));
    
    for (int i=0; i<N; i++) {
        ls[i].height=0;
        for (int j=0; j<10; j++) {
            ls[i].name[j]=0;
        }
    }
    
    for (int i=0; i<rest; i++) {
        last[i].height=0;
        for (int j=0; j<10; j++) {
            last[i].name[j]=0;
        }
    }
    
    for (int i=0; i<N/K; i++) {
        before[i].height=0;
        for (int j=0; j<10; j++) {
            before[i].name[j]=0;
        }
    }
    
    for (int i=0; i<N; i++) {
        scanf("%s %d",ls[i].name,&ls[i].height);
    }
    
    qsort(ls, N, sizeof(*ls), compar);
    
    for (int i=N-1,count=1; i>=N-rest; i--,count++) {
        fill1(ls[i], last, count, rest);
    }
    for (int i=0; i<rest; i++) {
        printf("%s",last[i].name);
        if (i!=rest-1) {
            printf(" ");
        }
    }
    printf("\n");
    
    for (int i=N-rest-1; i>=0; i-=N/K) {
        for (int j=i,count=1; j>i-N/K; j--,count++) {
            fill1(ls[j], before, count, N/K);
        }
        for (int j=0; j<N/K; j++) {
            printf("%s",before[j].name);
            if (j!=N/K-1) {
                printf(" ");
            }
        }
        printf("\n");
        for (int k=0; k<N/K; k++) {
            before[k].height=0;
            for (int l=0; before[k].name[l]; l++) {
                before[k].name[l]=0;
            }
        }
    }
}