#include <stdio.h>
#include <string.h>

int main(){
    int N,num,n,num1;
    int score[101];
    memset(score, 0, sizeof(score));
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d",&num);
        score[num]++;
    }
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&num1);
        printf("%d",score[num1]);
        if (i!=n-1) {
            printf(" ");
        }
    }
}