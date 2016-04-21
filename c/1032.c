#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,sch,score,max=0,name=0;;
    scanf("%d",&N);
    int* school=malloc((N+1)*sizeof(int*));
    
    for (int i=0; i<N+1; i++) {
        school[i]=0;
    }
    
    for (int i=1; i<=N; i++) {
        scanf("%d %d",&sch,&score);
        school[sch]+=score;
    }
    
    for (int i=1; i<=N; i++) {
        if (school[i]>max) {
            name=i;
            max=school[i];
        }
    }
    printf("%d %d",name,school[name]);
}