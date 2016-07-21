#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <limits.h>

typedef long long LL;

using namespace std;

LL INF=LONG_LONG_MAX;
LL map[256];

void init(){
    for (char c='0'; c<='9'; c++) {
        map[c]=c-48;
    }
    for (char c='a'; c<='z'; c++) {
        map[c]=c-'a'+10;
    }
}

LL convertNum10(char N[],LL radix,LL t){//计算结果并将其转换为10进制 t为上界
    LL ans=0;
    int length=(int)strlen(N);
    
    for (int i=0; i<length; i++) {
        ans+=map[N[i]]*pow(radix, length-i-1);
        if (ans<0||ans>t) {
            return -1;
        }
    }
    
    return ans;//返回－1或答案
}

LL FindLargestDigit(char N2[]){
    int length2=(int)strlen(N2);
    
    char temp=-1;
    LL low;
    
    for (int i=0; i<length2; i++) {
        if (N2[i]>temp) {
            temp=N2[i];
        }
    }
    
    low=map[temp]+1;
    
    return low;
}

int cmp(char N2[],LL mid,LL t){
    LL num=convertNum10(N2, mid, t);
    if (num<0) {
        return 1;//溢出，肯定大于t
    }
    if (t>num) {
        return -1;
    }else if (t==num) {
        return 0;
    }else{
        return 1;
    }
}

LL binarysearch(char N2[],LL low,LL high,LL t){
    LL mid;
    while (low<=high) {
        mid=(low+high)/2;
        int flag=cmp(N2,mid,t);
        if (flag==0) {
            return mid;
        }else if (flag==-1){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    char N1[15]={'\0'},N2[15]={'\0'};
    LL radix,tab;
    scanf("%s %s %lld %lld",N1,N2,&tab,&radix);
    
    init();
    
    if (tab==2) {//交换N1与N2
        char temp[15]={'\0'};
        strcpy(temp, N1);
        strcpy(N1, N2);
        strcpy(N2, temp);
    }
    
    LL t=convertNum10(N1,radix,INF);
    
    LL low=FindLargestDigit(N2);
    
    LL high=max(low, t)+1;//上界
    
    LL ans=binarysearch(N2,low,high,t);
    
    if (ans==-1) {
        printf("Impossible\n");
    }else{
        printf("%lld\n",ans);
    }
    return 0;
}