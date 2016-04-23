#include <stdio.h>

int main(){
    int team[1001]={};
    int N,a,b,c,max=0,maxteam=0;
    scanf("%d",&N);
    
    for (int i=0; i<N; i++) {
        scanf("%d-%d %d",&a,&b,&c);
        team[a]+=c;
        if (team[a]>max) {
            max=team[a];
            maxteam=a;
        }
    }
    
    printf("%d %d",maxteam,team[maxteam]);
}