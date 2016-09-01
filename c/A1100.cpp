#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

string unitdigit[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};

string tendigit[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

string numTostr[170];

map<string, int> strTonum;

void init(){
    for (int i=0; i<13; i++) {
        numTostr[i]=unitdigit[i];
        
        strTonum[unitdigit[i]]=i;
        
        numTostr[i*13]=tendigit[i];
        
        strTonum[tendigit[i]]=i*13;
    }
    
    for (int i=1; i<13; i++) {
        for (int j=1; j<13; j++) {
            string str=tendigit[i]+" "+unitdigit[j];
            numTostr[i*13+j]=str;
            strTonum[str]=i*13+j;
        }
    }
    
}

int main(){
    init();
    
    int T;
    
    scanf("%d%*c",&T);
    
    while (T--) {
        string str;
        getline(cin,str);
        
        if (str[0]>='0'&&str[0]<='9') {
            int num=0;
            for (int i=0; i<str.length(); i++) {
                num=num*10+str[i]-'0';
            }
            
            cout<<numTostr[num]<<endl;
        }else{
            cout<<strTonum[str]<<endl;
        }
    }
    
    return 0;
}