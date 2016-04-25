#include <stdio.h>

int main(){
    int N,D,flag1=0,flag2=0,count,day;
    double e,elec;
    
    scanf("%d%lf%d",&N,&e,&D);
    for (int i=0; i<N; i++) {
        count=0;
        scanf("%d",&day);
        for (int j=0; j<day; j++) {
            scanf("%lf",&elec);
            if (elec<e) {
                count++;
            }
        }
        if (count>day/2&&day>D) {
            flag2++;
        }else if (count>day/2){
            flag1++;
        }
    }
    
    printf("%.1lf%% %.1lf%%\n",flag1/(double)N*100.0,flag2/(double)N*100.0);
}