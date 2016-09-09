#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ans;

int n;

int main(){
    scanf("%d",&n);
    
    int flag=0,count1=0;
    string ID,password;
    
    for (int i=0; i<n; i++) {
        cin>>ID>>password;
        
        for (int i=0; i<(int)password.size(); i++) {
            if (password[i]=='1') {
                flag=1;
                password[i]='@';
            }else if (password[i]=='0'){
                flag=1;
                password[i]='%';
            }else if (password[i]=='l'){
                flag=1;
                password[i]='L';
            }else if (password[i]=='O'){
                flag=1;
                password[i]='o';
            }
        }
        
        if (flag==1) {
            count1++;
            ID+=' ';
            ID+=password;
            
            ans.push_back(ID);
        }
        
        flag=0;
    }
    
    if (ans.size()==0) {
        if (n==1) {
            printf("There is %d account and no account is modified\n",n);
        }else{
            printf("There are %d accounts and no account is modified\n",n);
        }
    }else{
        printf("%d\n",count1);
        
        for (int i=0; i<(int)ans.size(); i++) {
            printf("%s\n",ans[i].c_str());
        }
    }
}