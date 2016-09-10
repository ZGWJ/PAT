#include <cstdio>
#include <cstring>

const int maxn=10010;

char a[maxn],b[maxn];

bool HashTable[128];

int main(){
    gets(a);
    gets(b);
    
    int lenA=(int)strlen(a);
    int lenB=(int)strlen(b);
    
    for (int i=0; i<lenB; i++) {
        HashTable[b[i]]=true;
    }
    
    for (int i=0; i<lenA; i++) {
        if (HashTable[a[i]]==false) {
            printf("%c",a[i]);
        }
    }
    
    return 0;
}