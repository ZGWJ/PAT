#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void*pa,const void* pb){
    int ret=*(int*)pa-*(int*)pb;
    return ret;
}

int main(){
    int N,l=0,point=0,m=0,flag=0;
    scanf("%d",&N);
    int* all=malloc(N*sizeof(int*));
    int* yisi=malloc(N*sizeof(int*));
    int* sort=malloc(N*sizeof(int*));
    int* zhuyuan=malloc(N*sizeof(int*));
    
    for (int i=0; i<N; i++) {
        scanf("%d",&all[i]);
        sort[i]=all[i];
    }
    
    qsort(sort, N, sizeof(int), compar);
    
    for (int i=0; i<N; i++) {
        if (sort[i]==all[i]) {
            yisi[l]=i;
            l++;
        }
    }
    
    for (int j=0; j<l; j++) {//yisi
        for (int k=point; k<yisi[j]; k++) {//all
            if (all[k]>all[yisi[j]]) {
                while (all[yisi[j]]<all[k]) {
                    j++;
                    if (j>=l) {
                        flag=1;
                        break;
                    }
                }
                if (flag==1) {
                    break;
                }
            }
        }
        if (flag==0) {
            point=j;
            zhuyuan[m]=yisi[j];
            m++;
        }
        flag=0;
    }
    if (m==0) {
        printf("0\n");
        printf("\n");
    }else{
        printf("%d\n",m);
        for (int i=0; i<m; i++) {
            printf("%d",all[zhuyuan[i]]);
            if(i<m-1){
                printf(" ");
            }
        }
    }
}



----------------------------运行超时----------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compar(const void*pa,const void* pb){
    int ret=*(int*)pa-*(int*)pb;
    return ret;
}

int main(){
    FILE * fp1 = fopen("/Users/***/Desktop/11.txt", "r");
    long long a=clock();
    int N,low,high=-1,count=0,l=0,point=0,point1=0,flag=0;
    fscanf(fp1,"%d",&N);
    int* all=malloc(N*sizeof(int*));
    int* zhuyuan=malloc(N*sizeof(int*));
    int* sort=malloc(N*sizeof(int*));
    
    
    for (int i=0; i<N; i++) {
        fscanf(fp1,"%d",&all[i]);
        sort[i]=all[i];

    }
    
    qsort(sort, N, sizeof(int), compar);
    low=sort[0];
    for (int i=0; i<N; i++) {
        if (all[i]<=low&&all[i]>=high) {
            count++;
            zhuyuan[l]=all[i];
            l++;
            high=all[i];
            if (all[i]==low) {
                low=sort[point+1];
                point++;
                point1++;
            }
        }else if(all[i]>low){
            high=all[i];
            for (int k=point1+1; k<N; k++) {
                if (sort[k]==all[i]) {
                    if (k==N-1) {
                        point1=k;
                        flag=1;
                    }else{
                        point1=k+1;
                    }
                    if (point!=0) {
                        point=point1;
                        low=sort[point];
                    }
                    break;
                }
            }
        }else{
            if (all[i]==low) {
                point=point1;
                low=sort[point+1];
                point++;
                point1++;
            }
        }
        if (flag==1&&i<N-1) {
            break;
        }
    }
    printf("%d\n",count);
    for (int i=0; i<l; i++) {
        printf("%d",(int)zhuyuan[i]);
        if (i<l-1) {
            printf(" ");
        }
    }
    if (l==0) {
        printf("\n");
    }
    printf("\n");
    long long b=clock();
    long long c=b-a;
    printf("%lld",c);
}
