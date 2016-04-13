
#include <stdio.h>
#include <string.h>


int main(){
    int n;
    int i,j;
    scanf("%d",&n);
    for (j=0; j<n;j++) {
        char str[100]={NULL};
        scanf("%s",str);
        int count_P=0;
        int count_T=0;
        int jump=0;
        int sign=0;
        int sign_P=0;
        int sign_T=0;
        int sign_end=0;
        int num_a;
        int num_end;
        for (i=0; i<100; i++) {
            if (str[i]!='P'&&str[i]!='A'&&str[i]!='T') {
                printf("NO\n");
                jump=1;
                break;
            }

            if (str[i]=='P') {
                count_P++;
                sign_P=i;
                if (sign==0) {
                    sign=1;
                }
            }
            
            if (str[i]=='T') {
                if (sign==0) {
                    printf("NO\n");
                    jump=1;
                    break;
                }
                if (i==sign_P+1) {
                    printf("NO\n");
                    jump=1;
                    break;
                }
                count_T++;
                sign_T=i;
            }
            if (str[i+1]=='\0') {
                sign_end=i;
                break;
            }
        }
        if (jump==0) {
            num_a=sign_T-sign_P-2;
            num_end=sign_end-sign_T;
            if (count_P==1&&count_T==1) {
                if (num_end>=(num_a+1)*sign_P) {
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}