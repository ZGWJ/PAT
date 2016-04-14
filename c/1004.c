#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    
    char maxname[11]={};
    char maxnumber[11]={};
    
    char lowestname[11]={};
    char lowestnumber[11]={};
    
    int maxscore=0;
    int lowest_score=100;
    
    for (int i=0; i<n; i++) {
        
        int k=0;
        int l=0;
        int m=0;
        
        int count=0;
        int score1=0;
        
        char string[26]={};
        
        char name[11]={};
        char number[11]={};
        char score[4]={};
        

        scanf("%[^\n]",string);
        getchar();
        
        for (int j=0; j<=24; j++) {
            if (string[j]!=' ') {
                if (count==0) {
                    name[k]=string[j];
                    k++;
                }
                else if (count==1){
                    number[l]=string[j];
                    l++;
                }
                else{
                    score[m]=string[j];
                    m++;
                }
            }
            else{
                count++;
            }
            if (string[j+1]=='\0') {
                break;
            }
        }
        score1=atoi(score);
        if (score1>=maxscore) {
            for (int i=0; i<=9; i++) {
                maxname[i]=name[i];
                maxnumber[i]=number[i];
            }
            maxscore=score1;
        }
        if(score1<=lowest_score){
            for (int i=0; i<=9; i++) {
                lowestname[i]=name[i];
                lowestnumber[i]=number[i];
            }
            lowest_score=score1;
        }
    }
    printf("%s %s\n",maxname,maxnumber);
    printf("%s %s\n",lowestname,lowestnumber);
}