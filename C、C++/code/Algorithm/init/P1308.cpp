#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
string str[1000000];
int main(void){
    int now=-1,last=-1;//now用于指向当前的位置，last用于指向上一个空格的位置
    string temp="";
    string search="";//待查找
    getline(cin,search);
    getline(cin,temp);
    int index=0;
    for(int i=0;i<temp.length();i++){
        if(temp[i]==' '){ //如果当前是空格
            now=i;//当前空格的位置是i
            str[index].assign(temp,last+1,now-last-1);
            index++;
            last=now;//重置上一个位置的指针
        }
    }
    str[index].assign(temp,last+1,temp.length()-1-last);
    transform(search.begin(),search.end(),search.begin(),::tolower); //全部都进行转换
    int count=0;
    bool flag= false;
    int location=0;
    for(int i=0;i<=index;i++){
        transform(str[i].begin(),str[i].end(),str[i].begin(),::tolower);
        if(str[i]==search){
            count++;
            if(flag== false){
                flag= true;
                for(int j=0;j<i;j++){
                    location+=str[j].length()+1;
                }
            }
        }
    }
    if(location==0){
        cout<<-1<<endl;
    }else{
        cout<<count<<" "<<location<<endl;
    }
    return 0;
}