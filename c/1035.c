#include <stdio.h>
#include <stdlib.h>

void merge(int* num,int k,int len){
    if (k>=len) {
        k=len;
    }
    int start=0,end=0;
    for (int i=0; i<len; ) {
        start=i;
        end=(start+k>len?len:start+k);
        for (int m=end-1; m>=start; m--) {
            int iloc=-1,max=num[start],l=0;
            for(l=start;l<=m;l++)  if(num[l]>=max) iloc=l,max=num[l];
            if(iloc>=0) num[iloc]=num[l-1],num[l-1]=max;
        }
        i+=k;
    }
}

int main(){
    int N,j,flag=0,flag1=0;
    scanf("%d",&N);
    int num_init[101]={};
    int num_mid[101]={};
    int num[101]={};
    int num2[101]={};
    
    for (int i=0; i<N; i++) {
        scanf("%d",&num_init[i]);
    }
    for (int i=0; i<N; i++) {
        scanf("%d",&num_mid[i]);
    }
    
    for (int i=0; i<N; i++) {
        num[i+1]=num_init[i];
        num2[i]=num_init[i];
    }
    
    for (int i=2; i<=N; i++) {
        if (num[i]<num[i-1]) {
            num[0]=num[i];
            num[i]=num[i-1];
            for (j=i-2; num[0]<num[j]; --j) {
                num[j+1]=num[j];
            }
            num[j+1]=num[0];
        }
        for (int k=1; k<=N; k++) {
            if (num[k]!=num_mid[k-1]) {
                flag=1;
                break;
            }
        }
        if (flag==0) {
            flag1=1;
            printf("Insertion Sort\n");
            i++;
            if (num[i]<num[i-1]) {
                num[0]=num[i];
                num[i]=num[i-1];
            }
            for (j=i-2; num[0]<num[j]; --j) {
                num[j+1]=num[j];
            }
            num[j+1]=num[0];
            for (int k=1; k<=N; k++) {
                printf("%d",num[k]);
                if (k!=N) {
                    printf(" ");
                }
            }
            break;
        }
        flag=0;
    }
    if (flag1==0) {
        for (int i=1;;) {
            merge(num2,i,N);
            flag=0;
            for (int k=0; k<N; k++) {
                if (num2[k]!=num_mid[k]) {
                    flag=1;
                    break;
                }
            }
            if (flag==0) {
                merge(num2,2*i,N);
                printf("Merge Sort\n");
                for (int k=0; k<N; k++) {
                    printf("%d",num2[k]);
                    if (k!=N-1) {
                        printf(" ");
                    }
                }
                break;
            }
            i*=2;
            if (i>2*N) {
                break;
            }
        }
    }
}