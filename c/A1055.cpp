#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn=100100;

struct Range{
    int a;
    int b;
    int c;
}range[1010];

struct People{
    char name[10]={0};
    int age;
    int wealth;
}people[maxn];

bool cmp(People a,People b){
    if (a.wealth==b.wealth) {
        if (a.age==b.age) {
            int s=strcmp(a.name, b.name);
            return s<0;
        }
        return a.age<b.age;
    }
    return a.wealth>b.wealth;
}

int main(){
    int n,k;
    
    scanf("%d %d",&n,&k);
    
    for (int i=1; i<=n; i++) {
        scanf("%s %d %d",people[i].name,&people[i].age,&people[i].wealth);
    }
    
    for (int i=0; i<k; i++) {
        scanf("%d %d %d",&range[i].a,&range[i].b,&range[i].c);
    }
    
    sort(people+1, people+1+n, cmp);
    
    for (int i=0; i<k; i++) {
        printf("Case #%d:\n",i+1);
        int count=0;
        for (int j=1; j<=n; j++) {
            if (people[j].age<=range[i].c&&people[j].age>=range[i].b) {
                printf("%s %d %d\n",people[j].name,people[j].age,people[j].wealth);
                count++;
                if (count==range[i].a) {
                    break;
                }
            }
            if (j==n&&count==0) {
                printf("None\n");
            }
        }
    }
    
    return 0;
}