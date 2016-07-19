#include <cstdio>

int main(){
    int k,maxi = 0,maxj=0;
    bool flag=false;
    long long temp=0,max=-1;
    long long num[10001];
    
    scanf("%d",&k);
    
    for (int i=1; i<=k; i++) {
        scanf("%lld",&num[i]);
        if (num[i]>=0) {
            flag=true;
        }
    }
    
    for (int i=1; i<=k; i++) {
        for (int j=i; j<=k; j++) {
            temp+=num[j];
            if (temp>max) {
                maxi=i;
                maxj=j;
                max=temp;
            }
        }
        temp=0;
    }
    if (flag==false) {
        printf("0 %lld %lld",num[1],num[k]);
    }else{
        printf("%lld %lld %lld",max,num[maxi],num[maxj]);
    }
}