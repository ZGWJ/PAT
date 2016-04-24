#include <stdio.h>
#include <stdlib.h>
int **matrix,*all,guide=0;
int N,count=0,m,n;
struct position{
    int x;
    int y;
}filler={0,0},direction[4]={{1,0},{0,1},{-1,0},{0,-1}};

int compar(const void*pa,const void*pb){
    int ret=*(int*)pb-*(int*)pa;
    return  ret;
}

int canmove(){
    int x,y;
    x=filler.x+direction[guide].x;
    y=filler.y+direction[guide].y;
    if (x<0||x>=n||y<0||y>=m) {
        return 0;
    }else if (matrix[y][x]!=0){
        return 0;
    }
    return 1;
}

int move1(int count){
    matrix[filler.y][filler.x]=all[count];
    if (count==N-1) {
        return 0;
    }
    while (!canmove()) {
        guide=(guide+1)%4;
    }
    filler.x+=direction[guide].x;
    filler.y+=direction[guide].y;
    return 0;
}

int main(){
    int i,j;
    scanf("%d",&N);
    all=malloc(N*sizeof(int*));
    
    m=N,n=1;//find the m n
    for (int i=N; i>0; i--) {
        if (N%i==0) {
            if (i-N/i<0) {
                break;
            }
            if (i-N/i<m-n) {
                m=i;
                n=N/i;
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        scanf("%d",&all[i]);
    }
    
    qsort(all, N, sizeof(int), compar);
    
    matrix=(int**)malloc(m*sizeof(int*));
    
    for (int i=0; i<m; i++) {
        matrix[i]=(int*)calloc(n, sizeof(int));
    }
    while (count<N) {
        move1(count);
        count++;
    }
    
    for (i=0; i<m; i++) {
        for (j=0; j<n-1; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("%d\n",matrix[i][j]);
    }
}