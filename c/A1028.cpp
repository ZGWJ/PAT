#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn=100100;

struct Student{
    int id;
    char name[10]={0};
    int grade;
}student[maxn];

bool cmp1(Student a,Student b){
    return b.id>a.id;
}

bool cmp2(Student a,Student b){
    int s=strcmp(a.name, b.name);
    if (s!=0) {
        return s<0;
    }else{
        return a.id<b.id;
    }
}

bool cmp3(Student a,Student b){
    if (b.grade==a.grade) {
        return b.id>a.id;
    }
    return b.grade>a.grade;
}

int main(){
    int n,c;
    
    scanf("%d %d",&n,&c);
    
    for (int i=1; i<=n; i++) {
        scanf("%d",&student[i].id);
        scanf("%s",student[i].name);
        scanf("%d",&student[i].grade);
    }
    
    if (c==1) {
        sort(student+1, student+1+n, cmp1);
    }else if (c==2){
        sort(student+1, student+1+n, cmp2);
    }else{
        sort(student+1, student+1+n, cmp3);
    }
    
    for (int i=1; i<=n; i++) {
        printf("%06d %s %d\n",student[i].id,student[i].name,student[i].grade);
    }
    
    return 0;
}