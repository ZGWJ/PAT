#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map<string, set<int>> s1;
map<string, set<int>> s2;
map<string, set<int>> s3;
map<string, set<int>> s4;
map<string, set<int>> s5;

void query(map<string, set<int>>& s,string& str){
    if (s.find(str)==s.end()) {
        printf("Not Found\n");
    }else{
        for (set<int>::iterator it=s[str].begin(); it!=s[str].end(); it++) {
            printf("%07d\n",*it);
        }
    }
}

int main(){
    int n,id;
    scanf("%d",&n);
    
    char c;
    
    string title,auther,keywords,publisher,year;
    
    for (int i=0; i<n; i++) {
        scanf("%d",&id);
        getchar();
        
        getline(cin,title);
        s1[title].insert(id);
        
        getline(cin,auther);
        s2[auther].insert(id);
        
        while (cin>>keywords) {
            s3[keywords].insert(id);
            
            c=getchar();
            
            if (c=='\n') {
                break;
            }
        }
        
        getline(cin,publisher);
        s4[publisher].insert(id);
        
        getline(cin,year);
        s5[year].insert(id);
    }
    
    int m,type;
    
    string temp;
    
    scanf("%d",&m);
    
    for (int i=0; i<m; i++) {
        scanf("%d: ",&type);
        
        getline(cin, temp);
        
        cout<<type<<": "<<temp<<endl;
        
        if (type==1) {
            query(s1,temp);
        }else if (type==2){
            query(s2,temp);
        }else if (type==3){
            query(s3,temp);
        }else if (type==4){
            query(s4,temp);
        }else if (type==5){
            query(s5,temp);
        }
    }
    
    return 0;
}