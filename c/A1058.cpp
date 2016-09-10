#include <cstdio>

int main(){
    int a,b,c,d,e,f;
    
    int a1,b1,c1;
    
    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
    
    a1=a+d;
    b1=b+e;
    c1=c+f;
    
    if (c1>=29) {
        b1++;
        c1=c1%29;
    }
    
    if (b1>=17) {
        a1++;
        b1=b1%17;
    }
    
    printf("%d.%d.%d\n",a1,b1,c1);
    
    return 0;
}