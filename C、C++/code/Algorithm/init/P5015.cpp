#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(void){
    string s;
    getline(std::cin,s);
    int count=0;
    for (int i = 0; i <s.length() ; ++i) {
        if(s[i]!=' '){
            count++;
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}