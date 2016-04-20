#include <stdio.h>
#include <stdlib.h>

typedef struct people{
    char name[6];
    int date;
}people;



int compar(const void* pa,const void* pb){
    people a=*(people*)pa;
    people b=*(people*)pb;
    int ret;
    ret=b.date-a.date;
    return ret;
}

int main(){
    int N,time,count=0,young=0;
    char temp[11]={},name[6]={};
    scanf("%d",&N);
    people *people=malloc(N*sizeof(*people));

    for (int i=0; i<N; i++) {
        for (int j=0; j<6; j++) {
            people[i].name[j]=0;
        }
        people[i].date=0;
        scanf("%s",name);
        scanf("%s",temp);
        for (int j=0; j<11; j++) {
            if (temp[j]=='/') {
                temp[j]='0';
            }
        }
        time=atoi(temp);
        if (time<=2014009006&&time>=1814009006) {
            for (int j=0; j<6; j++) {
                people[i].name[j]=name[j];
            }
            people[i].date=time;
            count++;
        }
    }
    qsort(people, N, sizeof(*people), compar);
    for (int i=N-1; i>=0; i--) {
        if (people[i].date!=0) {
            young=i;
            break;
        }
    }
    if (people[0].date!=0) {
        printf("%d %s %s",count,people[young].name,people[0].name);
    }else{
        printf("0");
    }
}