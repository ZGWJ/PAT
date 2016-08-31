#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    char name[5];
};

int n,k;

vector<Student> student[2600];

bool cmp(Student a,Student b){
    int c=strcmp(a.name, b.name);
    return c<0;
}

int main(){
    scanf("%d %d",&n,&k);
    
    for (int i=0; i<n; i++) {
        Student temp;
        int x,y;
        
        scanf("%s",temp.name);
        scanf("%d",&x);
        
        for (int j=0; j<x; j++) {
            scanf("%d",&y);
            
            student[y].push_back(temp);
        }
    }
    
    for (int i=1; i<=k; i++) {
        printf("%d %d\n",i,(int)student[i].size());
        
        sort(student[i].begin(), student[i].end(), cmp);
        
        for (int j=0; j<student[i].size(); j++) {
            printf("%s\n",student[i][j].name);
        }
    }
    
    return 0;
}