#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m1;

string s1;

int main(){
    char a;
    while (1) {
        scanf("%c",&a);
        
        if ((a>='0'&&a<='9')||(a>='a'&&a<='z')) {
            s1+=a;
        }else if((a>='A'&&a<='Z')){
            a=a-'A'+'a';
            s1+=a;
        }else{
            if (!s1.empty()) {
                if (m1.find(s1)!=m1.end()) {
                    m1[s1]++;
                }else{
                    m1[s1]=1;
                }
                
                s1.clear();
            }
            
            if (a=='\n') {
                break;
            }
        }
    }
    
    int max=0;
    string res;
    
    for (map<string,int>::iterator it=m1.begin(); it!=m1.end(); it++) {
        if (it->second>max) {
            max=it->second;
            res=it->first;
        }
    }
    
    cout<<res<<" "<<max<<endl;
    
    return 0;
}