#include <stdio.h>
#include <string.h>

int main(){
    int count=0,flag=0,count1=0;
    char p[1001],q[1001];
    char boss[127];
    char xiaohong[127];
    memset(boss, 0, sizeof(boss));
    memset(xiaohong, 0, sizeof(xiaohong));
    memset(p, 0, sizeof(p));
    memset(q, 0, sizeof(q));
    scanf("%s",p);
    for (int i=0; i<strlen(p);i++) {
        count1++;
        boss[p[i]]++;
    }
    getchar();
    scanf("%s",q);
    for (int i=0; i<strlen(q); i++) {
        if (boss[q[i]]==0) {
            flag=1;
            count++;
        }else{
            boss[q[i]]--;
            count1--;
        }
    }
    if (flag==0) {
        printf("Yes %d",count1);
    }else{
        printf("No %d",count);
    }
}