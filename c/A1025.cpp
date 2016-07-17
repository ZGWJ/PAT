#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n;//考场数
struct Student{
        char ID[15];
    int score;
    int final_rank;
    int local_number;
    int local_rank;
}student[30100];


bool cmp1(Student a,Student b){
    if (a.score!=b.score) {
        return a.score>b.score;
    }else{
        return strcmp(a.ID, b.ID)<0;
    }
}

int main(){
    int r_total=0;
    for (int i=0; i<30100; i++) {
        student[i].score=-1;
    }
    
    scanf("%d",&n);
    for (int i=0; i<n; i++) {//第几考场
        int r;
        scanf("%d",&r);//考场内人数
        for (int j=1; j<=r; j++) {
            scanf("%s %d",student[i*300+j].ID,&student[i*300+j].score);
            student[i*300+j].local_number=i+1;
        }
        r_total+=r;
        sort(student+i*300+1, student+i*300+r+1, cmp1);
        student[i*300+1].local_rank=1;
        for (int j=2; j<=r; j++) {
            if (student[i*300+j].score==student[i*300+j-1].score) {
                student[i*300+j].local_rank=student[i*300+j-1].local_rank;
            }else{
                student[i*300+j].local_rank=j;
            }
        }
    }
    
    sort(student+1, student+30100, cmp1);
    
    student[1].final_rank=1;
    for (int i=2; i<=r_total; i++) {
        if (student[i].score==student[i-1].score) {
            student[i].final_rank=student[i-1].final_rank;
        }else{
            student[i].final_rank=i;
        }
        
    }
    
    printf("%d\n",r_total);
    for (int i=1; i<=r_total; i++) {
        printf("%s %d %d %d",student[i].ID,student[i].final_rank,student[i].local_number,student[i].local_rank);
        if (i!=r_total) {
            printf("\n");
        }
    }
}