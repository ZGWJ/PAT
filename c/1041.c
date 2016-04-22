#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    long long license;
    int exam;
}list;

int main(){
    long long license;
    int N,text,exam,n,find;
    scanf("%d",&N);
    list* system=malloc(N*sizeof(list*));
    for (int i=0; i<N; i++) {
        scanf("%lld %d %d",&license,&text,&exam);
        system[text].license=license;
        system[text].exam=exam;
    }
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&find);
        printf("%lld %d\n",system[find].license,system[find].exam);
    }
}