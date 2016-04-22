char all[100000];

int main(){
    int i=0,p_count=0;
    long long pa_count,sum=0,len;
    memset(all, 0, sizeof(all));
    scanf("%s",all);
    len=strlen(all);
    while (i<len) {
        if (all[i]=='P') {
            p_count++;
        }else if (all[i]=='A'){
            pa_count+=p_count;
            pa_count%=1000000007;
        }else{
            sum+=pa_count;
            sum%=1000000007;
        }
        i++;
    }
    printf("%lld",sum);
}

－－－－－－－－－－－－－－－－－－超时算法－－－－－－－－－－－－－－－－－－
#include <stdio.h>
#include <string.h>

struct info{
    int loc;
    long long count,sum;
}P[100000],T[100000];

char all[100000];

int main(){
    int start=-1,end=-1,j=0,l=0;
    long long count,count1=0,sum;
    memset(all, 0, sizeof(all));
    scanf("%s",all);
    for (int i=0; i<strlen(all); i++) {
        if (all[i]=='P') {
            start=i;
            break;
        }
    }
    for (unsigned long i=strlen(all)-1; i>0; i--) {
        if (all[i]=='T') {
            end=(int)i;
            break;
        }
    }
    for (int i=start; i<end; i++) {
        if (all[i]=='P') {
            P[j].loc=i;
            P[j].count=count;
            j++;
        }
        if (all[i]=='A') {
            count++;
        }
    }
    for (int i=end; i>start; i--) {
        if (all[i]=='T') {
            T[l].loc=i;
            T[l].count=count1;
            l++;
        }
        if (all[i]=='A') {
            count1++;
        }
    }
    
    for (int k=0; k<j; k++) {
        for (int m=0; m<l; m++) {
            if (P[k].loc<T[m].loc) {
                sum+=(count-P[k].count-T[m].count);
            }else{
                break;
            }
        }
    }
    sum=sum%1000000007;
    printf("%lld",sum);
}