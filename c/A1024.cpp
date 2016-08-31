#include <cstdio>
#include <cstring>

char n[300]={0};
char n1[300]={0};
int q;

int atoi(char n){
    return n-'0';
}

void shit(){
    int flag=0;
    
    int i=0;
    int j=(int)strlen(n)-1;
    
    while (i<j) {
        char temp=n[i];
        n[i]=n[j];
        n[j]=temp;
        i++;
        j--;
    }
    
    for (int k=(int)strlen(n)-1; k>=0; k--) {
        n1[k+1]='\0';
        
        if (flag==1) {
            n1[k+1]++;
        }
        
        if ((atoi(n1[k])+atoi(n[k]))>=10) {
            flag=1;
        }else{
            flag=0;
        }
        
        n1[k+1]+=((atoi(n1[k])+atoi(n[k])))%10+'0';
        
        if (n1[k+1]==':') {
            flag=1;
            n1[k+1]='0';
        }
    }
    
    
    
    if (flag==1) {
        n1[0]='1';
    }else{
        for (int i=0; i<strlen(n); i++) {
            n1[i]=n1[i+1];
        }
        n1[(int)strlen(n)]='\0';
    }
    
    for (int k=0; k<=strlen(n1); k++) {
        n[k]=n1[k];
    }
}

bool judge(){
    int i=0;
    int j=(int)strlen(n1);
    while (i<j-1) {
        if (n1[i]!=n1[j-1]) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

int main(){
    
    scanf("%s %d",n,&q);
    
    for (int i=0; i<=strlen(n); i++) {
        n1[i]=n[i];
    }
    
    if (judge()) {
        printf("%s\n",n1);
        printf("%d\n",0);
        return 0;
    }
    
    for (int i=1; i<=q; i++) {
        shit();
        if (judge()) {
            printf("%s\n",n1);
            printf("%d\n",i);
            return 0;
        }
    }
    
    printf("%s\n",n1);
    printf("%d\n",q);
    
    return 0;
}