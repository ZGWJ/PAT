#include <cstdio>

int n;

char eng[5]={'S','H','C','D','J'};

int order[55];

int start[55],end[55];

int main(){
    scanf("%d",&n);
    
    for (int i=0; i<54; i++) {
        scanf("%d",&order[i]);
    }
    
    for (int i=0; i<54; i++) {
        start[i]=i+1;
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<54; j++) {
            end[order[j]-1]=start[j];
        }
        for (int j=0; j<54; j++) {
            start[j]=end[j];
        }
    }
    
    for (int i=0; i<54; i++) {
        printf("%c%d",eng[(end[i]-1)/13],(end[i]-1)%13+1);
        if (i!=53){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    
    return 0;
}