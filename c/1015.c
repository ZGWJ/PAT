#include <stdio.h>
#include <stdlib.h>

int N,L,H,num=0;
typedef struct info{
    int id,de,cai,sum,type;
}info;

int compar(const void*pa,const void*pb);
int get_type(int de,int cai);

int main(){
    
    scanf("%d%d%d",&N,&L,&H);
    info *xs=malloc(N*sizeof(*xs));
    
    for (int i=0; i<N; i++) {
        scanf("%d%d%d",&xs[i].id,&xs[i].de,&xs[i].cai);
        
        xs[i].sum=xs[i].de+xs[i].cai;
        xs[i].type=get_type(xs[i].de,xs[i].cai);
        if (xs[i].type!=5) {
            num++;
        }
    }
    printf("%d\n",num);
    
    qsort(xs, N, sizeof(*xs), compar);
    for (int i=0; i<num; i++) {
        printf("%d %d %d\n",xs[i].id,xs[i].de,xs[i].cai);
    }
    free(xs);
    return 0;
}

int compar(const void*pa,const void*pb){
    info a=*(info*)pa;
    info b=*(info*)pb;
    int ret;
    
    if (a.type==b.type) {
        if (a.sum==b.sum) {
            if (a.de==b.de) {
                ret=a.id-b.id;
            }else{
                ret=b.de-a.de;
            }
        }else{
            ret=b.sum-a.sum;
        }
    }else{
        ret=a.type-b.type;
    }
    return ret;
}

int get_type(int de,int cai){
    int type;
    if (de>=H) {
        if (cai>=H) {
            type=1;
        }else if (cai>=L){
            type=2;
        }else{
            type=5;
        }
    }else if(de>=L){
        if (cai>=H) {
            type=4;
        }else if (cai>=L){
            if (de>=cai) {
                type=3;
            }else{
                type=4;
            }
        }else{
            type=5;
        }
    }else{
        type=5;
    }
    return type;
}