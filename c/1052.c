#include <stdio.h>
#include <string.h>

int main(){
    char emotion[3][11][5]={},buf[60]={},*pbuf=buf,flag=0;
    int offset[3],j,N,index;
    
    for (int i=0; i<3; i++) {//emotion
        gets(buf);
        pbuf=buf;
        offset[i]=0;
        while (*pbuf) {
            while (*pbuf!='['&&*pbuf!=0) {
                pbuf++;
            }
            if (*pbuf==0) {
                break;
            }
            pbuf++;
            j=1;//找到]的位置，即为j
            while (*(pbuf+j)!=']') {
                j++;
            }
            *(pbuf+j)=0;
            strcpy(emotion[i][offset[i]++], pbuf);
            pbuf+=j;//*pbuf==']'
            pbuf++;
        }
    }
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        flag=0;
        pbuf=buf;
        for (int j=0; j<5; j++) {
            scanf("%d",&index);
            if (flag) {
                continue;
            }
            if (index-1>=offset[j>2?4-j:j]||index<1) {
                printf("Are you kidding me? @\\/@\n");
                flag=1;
            }else{
                strcpy(pbuf, emotion[j>2?4-j:j][index-1]);
                pbuf+=strlen(emotion[j>2?4-j:j][index-1]);
                if (j==0) {
                    *(pbuf++)='(';
                }
                if (j==3) {
                    *(pbuf++)=')';
                }
            }
        }
        *pbuf=0;
        if (!flag) {
            printf("%s\n",buf);
        }
    }
}