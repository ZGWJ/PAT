#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s1;

int main(){
    int a=-1,b=-1,temp;
    
    cin>>s1;
    
    for (int i=3; i<s1.size(); i++) {
        temp=(int)(s1.size()+2-i)/2;
        
        if (temp<=i) {
            if (temp>=a) {
                a=temp;
            }
        }
    }
    
    a=a-1;
    b=(int)s1.size()-2*a;
    
    for (int i=0,j=(int)s1.size()-1; i<a; i++,j--) {
        printf("%c",s1[i]);
        for (int k=0; k<b-2; k++) {
            printf(" ");
        }
        printf("%c\n",s1[j]);
    }
    
    for (int i=a; i<a+b; i++) {
        printf("%c",s1[i]);
    }
    
    printf("\n");
    
    return 0;
}